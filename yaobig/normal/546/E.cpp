#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300
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
//Clear when initializing.
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
        cur[now]=id;
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

int a[maxn+5],b[maxn+5];

int ans[maxn+5][maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int SUM=0,N=n*2;
    src=++N; sink=++N;

    rep(i,1,n) scanf("%d",&a[i]),SUM+=a[i],ans[i][i]+=a[i];
    rep(i,1,n) scanf("%d",&b[i]),SUM-=b[i];
    if(SUM!=0) {puts("NO"); return 0;}
    rep(i,1,n)
    {
        add(src,i,a[i]);
        add(i,i+n,a[i]);
        add(i,sink,b[i]);
        SUM+=a[i];
    }
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        add(x+n,y,inf);
        add(y+n,x,inf);
    }
    int A=maxflow(N);
    if(A!=SUM) puts("NO");
    else
    {
        puts("YES");
        rep(now,1,n) for(auto id: to[now+n])
        {
            if(id&1) continue;
            int i=id^1;
            int v=e[id].v;
            if(e[i].c>0) ans[now][now]-=e[i].c,ans[now][v]+=e[i].c;
        }
        rep(i,1,n) rep(j,1,n) printf("%d%c",ans[i][j]," \n"[j==n]);
    }
    return 0;
}