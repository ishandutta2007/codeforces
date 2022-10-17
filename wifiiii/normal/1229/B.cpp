
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 100005;
vector<int> g[maxn];

ll a[maxn];
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
vector<pair<ll,ll>> dp[maxn];
const int mod = 1e9+7;
ll ans = 0;
void dfs(int u,int fa)
{
    if(fa != -1)
    {
        vector<pair<ll,ll>> tmp;
        tmp.push_back({a[u], 1});
        for(auto p : dp[fa])
        {
            ll x = gcd(p.first, a[u]);
            tmp.push_back({x,p.second});
        }
        sort(all(tmp));
        ll cur = 0;
        for(int i=0;i<tmp.size();++i) {
            cur += tmp[i].second;
            if(i+1==tmp.size() || tmp[i].first != tmp[i+1].first) {
                dp[u].push_back({tmp[i].first, cur});
                cur = 0;
            }
        }
    }
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i) for(auto p:dp[i]) ans+=p.first%mod*p.second%mod;
    ans %= mod;
    cout<<ans<<endl;
}