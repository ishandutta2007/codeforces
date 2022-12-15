#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MN = 2e5+5, mod = 998244353;
vector<int> a[2], dp[2];
int n, k, i, x, ans1, ans2, cnt[2], sp, dif;
int qpow(int b,int exp){
    if(!exp) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1);return 1LL*r*r%mod;}
}
signed main(){
    for(scanf("%lld%lld",&n,&k),i=1;i<=n;i++){
        scanf("%lld",&x);
        a[i%2].push_back(x);
        dp[i%2].push_back(0);
    }
    dp[0].push_back(0); dp[1].push_back(0);
    for(int j=0;j<2;j++){
        dif = sp = 0;
        for(i=(int)a[j].size()-2;i>=0;i--){
            if(a[j][i+1]==-1) cnt[j]++;
            if(a[j][i]==-1&&a[j][i+1]==-1){
                dp[j][i]=1LL*k*(dp[j][i+1]);
                dp[j][i]=(dp[j][i]+1LL*(qpow(k,cnt[j])-dp[j][i+1]+mod)%mod)%mod;
                dif = -dif;
            }
            else if(a[j][i]==-1){
                dp[j][i]=1LL*k*dp[j][i+1];
                sp = a[j][i+1]; dif = (qpow(k,cnt[j])-dp[j][i+1]+mod)%mod;
                dp[j][i]=(1LL*dp[j][i]+dif+mod)%mod;
            }
            else if(a[j][i+1]==-1){
                int good = (qpow(k,cnt[j])-dp[j][i+1]+mod)%mod;
                int base = 1LL*(good+dif)*qpow(k,mod-2)%mod;
                dp[j][i]=dp[j][i+1];
                if(a[j][i]==sp)dp[j][i]=(1LL*dp[j][i]+base-dif+mod)%mod;
                else dp[j][i]=(1LL*dp[j][i]+base)%mod;
            }
            else{
                if(a[j][i+1]==a[j][i]) dp[j][i]=qpow(k,cnt[j]);
                else dp[j][i]=dp[j][i+1];
            }
        }
    }
    if(a[0][0]==-1) cnt[0]++;
    if(a[1][0]==-1) cnt[1]++;
    ans1 = (qpow(k,cnt[0])-dp[0][0]+mod)%mod;
    ans2 = (qpow(k,cnt[1])-dp[1][0]+mod)%mod;
    printf("%lld\n",(ans1*ans2)%mod);
    return 0;
}