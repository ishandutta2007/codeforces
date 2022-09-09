#include <bits/stdc++.h>
using namespace std;
const int N=500050;
char s[N];
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        int bal=0;
        vector<int> cnt(2*n,0);
        for(int i=1;i<=n;i++){
            int add=s[i]=='0'?1:-1;
            cnt[min(bal,bal+add)+n]++;
            bal+=add;
        }
        int las=bal+n;
        bal=n;
        for(int i=1;i<=n;i++){
            if(cnt[bal]>1||cnt[bal-1]==0){
                s[i]='0';
                cnt[bal]--;
                bal++;
            }else{
                s[i]='1';
                cnt[bal-1]--;
                bal--;
            }
        }
        printf("%s\n",s+1);
    }
    return 0;
}