#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int inv9 = 443664157;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r%mod;}
ll pw[300005];
ll calc(ll x) {
    ll ans=((3*x+1)*pw[x]%mod+(x&1?1:-1))%mod*inv9%mod;
    if(ans<0) ans+=mod;
    return ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pw[0]=1; for(int i=1;i<=n*m;++i) pw[i]=pw[i-1]*2%mod;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
    vector<vector<int>> vis(n,vector<int>(m));
    int o=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(a[i][j]=='o') ++o;
    ll ans=0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(a[i][j]=='*' || vis[i][j]) continue;
            int cnt=0;
            for(int k=j;k<m;++k) {
                if(a[i][k]=='*') break;
                ++cnt;
                vis[i][k]=1;
            }
            if(cnt>1) ans+=calc(cnt-1)*pw[o-cnt]%mod;
        }
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) vis[i][j]=0;
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            if(a[j][i]=='*' || vis[j][i]) continue;
            int cnt=0;
            for(int k=j;k<n;++k) {
                if(a[k][i]=='*') break;
                ++cnt;
                vis[k][i]=1;
            }
            if(cnt>1) ans+=calc(cnt-1)*pw[o-cnt]%mod;
        }
    }
    ans%=mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}