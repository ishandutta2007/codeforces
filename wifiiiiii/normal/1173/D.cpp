#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

const int mod = 998244353;
int deg[200005];
ll fac[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    fac[0]=1;
    rep(i,n) fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    ll ans = 1;
    rep(i,n) (ans *= fac[deg[i]]) %= mod;
    (ans *= n) %= mod;
    cout<<ans<<endl;
}