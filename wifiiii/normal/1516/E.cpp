#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 205;
const int mod = 1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r%mod;}
ll f[maxn], rf[maxn], g[maxn*2];
ll dp[205][205],ans[205];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0]=rf[0]=1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod,rf[i]=fpow(f[i],mod-2);
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=1;i<=k;++i) {
        for(int j=k;j>=0;--j) {
            for(int l=k;l>=0;--l) {
                if(!dp[j][l]) continue;
                ll inv=fpow(i+1,mod-2),tot=inv;
                for(int r=1;j+i*r<=k&&j+i*r+l+r<=n;++r) {
                    dp[j+i*r][l+r]=(dp[j+i*r][l+r]+dp[j][l]*rf[r]%mod*tot%mod)%mod;
                    tot=tot*inv%mod;
                }
            }
        }
    }
    g[0]=n;
    for(int i=1;i<=k+k;++i) g[i]=g[i-1]*(n-i)%mod;
    for(int i=1;i<=k;++i) {
        for(int j=1;j<=k;++j) {
            if(i+j>n) break;
            ans[i]+=dp[i][j]*g[i+j-1]%mod;
        }
        ans[i]%=mod;
    }
//    for(int i=1;i<=k;++i) {
//        for(int l=1;l<=k;++l) {
//            cout<<dp[i][l]<<" ";
//        }
//        cout<<endl;
//    }
    ans[0]=1;
    for(int i=2;i<=k;++i) ans[i]=(ans[i-2]+ans[i])%mod;
    for(int i=1;i<=k;++i) cout<<ans[i]<<" ";cout<<endl;
}