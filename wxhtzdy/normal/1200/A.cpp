#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char s[n];
    scanf("%s",&s);
    int r[10];
    for(int i=0;i<10;i++)r[i]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            for(int j=0;j<10;j++){
                if(r[j]==0){
                    r[j]=1;
                    break;
                }
            }
        }else{
            if(s[i]=='R'){
                for(int j=9;j>=0;j--){
                    if(r[j]==0){
                        r[j]=1;
                        break;
                    }
                }
            }else{
                r[(int)(s[i]-'0')]=0;
            }
        }
    }
    for(int i=0;i<10;i++)printf("%i",r[i]);
    return 0;
}