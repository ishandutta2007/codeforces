#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 50
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[maxn+5][maxn+5][maxn+5][maxn+5];
vector<pii> e[maxn+5];
int sz[maxn+5];

inline void chmax(int& x,int y) {if(y>x) x=y;}

void calsz(int now,int fa)
{
    for(auto [v,w]: e[now]) if(v!=fa) 
    {
        calsz(v,now);
        sz[now]+=sz[v];
    }
}

int dfs(int u,int v,int x,int y)
{
    if(dp[u][v][x][y]!=-1) return dp[u][v][x][y];
    if(x==0 && y==0) return dp[u][v][x][y]=0;
    if((int)e[v].size()==1) return dp[u][v][x][y]=dfs(v,u,y,0)+(y?e[v][0].SE:0);

    int l=0,r=2500*(x+y)+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int left=x;
        for(auto [t,w]: e[v]) if(t!=u)
        {  
            if(left==0) break;
            rep(i,1,x) 
            {
                if(dfs(v,t,i,y+x-i)+w>=mid) left--; else break;
                if(left==0) break;
            }
        }
        if(left==0) l=mid+1;
        else r=mid;
    }
    return dp[u][v][x][y]=l-1;
}

int main()
{
    int n; scanf("%d",&n); 
    rep(i,1,n-1)
    {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        e[u].pb({v,w});
        e[v].pb({u,w});
    }
    int s; scanf("%d",&s);
    int m; scanf("%d",&m);
    rep(i,1,m)
    {
        int x; scanf("%d",&x); sz[x]++;
    }
    calsz(s,0);

    memset(dp,-1,sizeof dp);

    int mn=inf;
    for(auto [v,w]: e[s]) mn=min(mn,dfs(s,v,sz[v],m-sz[v])+w);
    printf("%d\n",mn);
    return 0;
}