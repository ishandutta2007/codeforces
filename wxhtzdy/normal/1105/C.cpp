#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int mul(int x,int y){return (long long)x*y%mod;}
int cnt[3],dp[N][3];
int main(){
    int n,l,r;scanf("%i%i%i",&n,&l,&r);
    while(l%3!=0)l--,cnt[l%3]--;
    while(r%3!=0)r++,cnt[r%3]--;
    cnt[0]+=(r-l)/3+1;
    cnt[1]+=(r-l)/3;
    cnt[2]+=(r-l)/3;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                dp[i][x]=add(dp[i][x],mul(dp[i-1][(x-y+3)%3],cnt[y]));
            }
        }
    }
    printf("%i\n",dp[n][0]);
    return 0;
}