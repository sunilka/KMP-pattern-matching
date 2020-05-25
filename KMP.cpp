//KMP string matching full implementation
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nooftestcases;
    cin>>nooftestcases;

    while(nooftestcases--){
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        int lps[pat.length()];
        lps[0] = 0;

        int i=1;
        int j=0;

        while(i<pat.length()){

            if(pat[i] == pat[j]){
                lps[i] = j+1;
                j++;
                i++;
            }

            else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }

        int flag = 0;
        i =0;
        j =0;

        while(i<s.length()){
            if(pat[j] == s[i]){
                i++;
                j++;
            }

            if(j == pat.length()){
                flag = 1;
                cout<<"\n Hurray, pattern has been found at index : "<<(i-j)<<endl;
                j = lps[j-1];
            }

            else if (i < s.length() && pat[j] != s[i]){

                if(j == 0){
                    i++;
                }

                else{
                    j = lps[j-1];
                }
            }
        }
        if(!flag)
            printf("\n sorry... no such patten exists in the string :( \n");

    }
}
