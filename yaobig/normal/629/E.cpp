#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int anc[maxn+5][18],dep[maxn+5],sz[maxn+5],sz2[maxn+5];
ll lensum[maxn+5],lensum2[maxn+5];

void dfs(int now,int fa)
{
    dep[now]=dep[fa]+1;
    anc[now][0]=fa;
    sz[now]=1;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        sz[now]+=sz[v];
        lensum[now]+=lensum[v]+sz[v];
    }
}

void dfs2(int now,int fa,ll L,int S)
{
    lensum2[now]=L;
    sz2[now]=S;
    for(auto v: e[now]) if(v!=fa) dfs2(v,now,L+S+lensum[now]-lensum[v]-sz[v],S+sz[now]-sz[v]);
}

int swim(int x,int h)
{
    for(int i=0;h;i++)
    {
        if(h&1) x=anc[x][i];
        h>>=1;
    }
    return x;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    x=swim(x,dep[x]-dep[y]);
    if(x==y) return x;
    per(i,0,16) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0,0,0);
    rep(j,1,16) rep(i,1,n) anc[i][j]=anc[anc[i][j-1]][j-1];
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(dep[x]<dep[y]) swap(x,y);
        int l=lca(x,y);
        if(l!=y)
        {
            db ans=dep[x]+dep[y]-dep[l]*2+1;
            ans+=(db)lensum[x]/sz[x]+(db)lensum[y]/sz[y];
            printf("%.10f\n",ans);
        }
        else
        {
            db ans=dep[x]-dep[y]+1;
            int son_y=swim(x,dep[x]-dep[y]-1);
            ans+=(db)lensum[x]/sz[x]+(db)lensum2[son_y]/sz2[son_y];
            printf("%.10f\n",ans);
        }
    }
    return 0;
}