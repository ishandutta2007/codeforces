#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 80010
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct E
{
    int u,v,c;
    E(){}
    E(int u,int v,int c):u(u),v(v),c(c){}
};

vector<E> e;
vi to[maxn+5];

int d[maxn+5],src,sink,cur[maxn+5];

void add(int u,int v,int c)
{
    to[u].pb(e.size()); e.pb(E(u,v,c));
    to[v].pb(e.size()); e.pb(E(v,u,0));
}
int bfs(int n)
{
    rep(i,1,n) d[i]=-1;
    queue<int> q;
    q.push(src); d[src]=0;
    while(q.size())
    {
        int now=q.front(); q.pop();
        for(auto i: to[now])
        {
            int v=e[i].v;
            if(e[i].c>0 && d[v]==-1)
            {
                d[v]=d[now]+1;
                q.push(v);
            }
        }
    }
    return d[sink]!=-1;
}
int dfs(int now,int f)
{
    if(now==sink) return f;
    int r=0,l=to[now].size();
    for(int &id=cur[now];id<l && r<f;id++)
    {
        int i=to[now][id],v=e[i].v;
        if(e[i].c>0 && d[v]==d[now]+1)
        {
            int tmp=min(f-r,e[i].c);
            int x=dfs(v,tmp);
            r+=x;
            e[i].c-=x;
            e[i^1].c+=x;
        }
    }
    if(r!=f) d[now]=-2;
    return r;
}
int maxflow(int n)
{
    int flow=0;
    while(bfs(n))
    {
        rep(i,1,n) cur[i]=0;
        flow+=dfs(src,inf);
    }
    return flow;
}

char g[205][205];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",g[i]+1);
    int cnt=0;
    rep(i,1,n) rep(j,1,m) cnt+=g[i][j]=='#';
    int N=n*m*2;
    src=++N; sink=++N;
    rep(i,1,n-1) rep(j,1,m) if(g[i][j]=='#' && g[i+1][j]=='#') add(src,(i-1)*m+j,1),cnt--;
    rep(i,1,n) rep(j,1,m-1) if(g[i][j]=='#' && g[i][j+1]=='#') add(n*m+(i-1)*m+j,sink,1),cnt--;
    rep(i,1,n-1) rep(j,1,m) if(g[i][j]=='#' && g[i+1][j]=='#')
    {
        int id=(i-1)*m+j;
        if(g[i][j+1]=='#') add(id,n*m+(i-1)*m+j,1);
        if(g[i][j-1]=='#') add(id,n*m+(i-1)*m+j-1,1);
        if(g[i+1][j+1]=='#') add(id,n*m+i*m+j,1);
        if(g[i+1][j-1]=='#') add(id,n*m+i*m+j-1,1);
    }
    printf("%d\n",cnt+maxflow(N));
    return 0;
}