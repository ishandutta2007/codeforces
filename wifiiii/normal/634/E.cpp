#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
int a[maxn], f[maxn];
vector<int> g[maxn];
int dp[maxn],sz[maxn],szf[maxn];
struct node {
    int mx1=0,mx2=0,mi1=0,mi2=0;
    void insert(int i,int x)
    {
        if(x>=mx1)
        {
            mx2=mx1,mi2=mi1;
            mi1=i,mx1=x;
        }
        else if(x>=mx2)
        {
            mx2=x,mi2=i;
        }
    }
}b[maxn];
int par[maxn];
void dfs(int u,int fa)
{
    par[u]=fa;sz[u]=1;
    if(f[u]) dp[u]=1;
    else dp[u]=-1e9;
    if(f[u]) szf[u]=1;
    else szf[u]=0;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        szf[u]+=szf[v];
        if(sz[v]==szf[v]) dp[u]+=dp[v];
        else b[u].insert(v,dp[v]);
    }
    dp[u]+=b[u].mx1;
}
int ok = 0;
int n,k;
void dfs2(int i)
{
    if(ok) return;
    if(par[i])
    {
        if(n - sz[i] == szf[1] - szf[i]) // par edge clear
        {
            if(dp[i] + n - sz[i] >= k)
            {
                ok = 1;
                return;
            }
            dp[i] += n - sz[i]; // update
        }
        else // par edge not clear
        {
            // first, calculate the answer of new edge without this node
            int ans = dp[par[i]];
            if(sz[i] == szf[i]) // this node clear
            {
                ans -= sz[i];
            }
            else if(i == b[par[i]].mi1) // this node is max
            {
                ans -= b[par[i]].mx1;
                ans += b[par[i]].mx2;
            }
//          cout << "ans" << " " << ans << endl;
            // then, if the answer is greater than mx, change to it
            if(ans > b[i].mx1)
            {
                dp[i] -= b[i].mx1;
                dp[i] += ans;
            }
            b[i].insert(par[i], ans);
            if(dp[i] >= k)
            {
                ok = 1;
                return;
            }
//          cout << i << " " << tmp << endl;
        }
    }
    for(int v:g[i])
    {
        if(v==par[i]) continue;
        dfs2(v);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>k;
    ii cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int lo=1,hi=1e6;
    while(lo<hi)
    {
        memset(dp,0,sizeof(dp));
        memset(sz,0,sizeof(dp));
        memset(szf,0,sizeof(dp));
        memset(par,0,sizeof(dp));
        memset(f,0,sizeof(dp));
        ii b[i].mx1=b[i].mx2=b[i].mi1=b[i].mi2=0;
        int mid=(lo+hi+1)/2;
        for(int i=1;i<=n;++i) if(a[i]>=mid) f[i]=1;else f[i]=0;
        dfs(1,-1);
        ok = 0;
        if(dp[1] >= k) ok = 1;
        else dfs2(1);
        if(ok) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
}