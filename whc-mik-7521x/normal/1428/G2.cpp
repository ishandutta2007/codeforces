#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long k,val[N],q;
long long dp[N],ddp[N];
vector<pair<long long,long long>>vec;
void ins(long long v,long long w){
    vec.push_back({v,w});
}
void solve(){
    memset(dp,-63,sizeof dp);
    dp[0]=0;
    for(auto it:vec){
        for(long long o=1e6;o>=it.first;o--){
            dp[o]=max(dp[o],dp[o-it.first]+it.second);
        }
    }
}
int main(){
    scanf("%lld",&k);
    for(long long i=0;i<=5;i++)scanf("%lld",&val[i]);
    for(long long i=0,o=1;i<=5;i++,o*=10){
        long long now=(k-1)*3,kk=1;
        while(now>kk)ins(o*kk*3,1ll*val[i]*kk),now-=kk,kk<<=1;
        ins(o*now*3,1ll*val[i]*now);
    }
    solve();
    for(long long i=0,o=1;i<=5;i++,o*=10){
        memset(ddp,-63,sizeof ddp);
        for(long long j=0;j<=9;j++){
            long long w=j%3==0?(j/3)*1ll*val[i]:0ll,v=o*j;
            for(long long pp=v;pp<=1e6;pp++)ddp[pp]=max(ddp[pp],dp[pp-v]+w);
        }
        swap(dp,ddp);
    }
    scanf("%lld",&q);
    while(q--){
        long long x;
        scanf("%lld",&x);
        printf("%lld\n",dp[x]);
    }
    return 0;
}
//