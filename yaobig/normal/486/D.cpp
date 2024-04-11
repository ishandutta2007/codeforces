#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int val[maxn+5];
bool vis[maxn+5];
vi e[maxn+5];
int low,d;

ll dfs(int now,int fa)
{
    ll res=1;
    for(auto v: e[now]) if(val[v]>=low && val[v]<=low+d && v!=fa && vis[v]==0) res=res*(1+dfs(v,now))%mod;
    return res;
}

int main()
{
    int n; scanf("%d%d",&d,&n);
    rep(i,1,n) scanf("%d",&val[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    ll ans=0;
    vi V; rep(i,1,n) V.pb(val[i]);
    sort(V.begin(),V.end()); V.erase(unique(V.begin(),V.end()),V.end());
    for(auto vv: V)
    {
        memset(vis,0,sizeof vis);
        low=vv;
        rep(i,1,n) if(val[i]==low) {ans=(ans+dfs(i,0))%mod; vis[i]=1;}
    }
    printf("%I64d\n",ans);
    return 0;
}