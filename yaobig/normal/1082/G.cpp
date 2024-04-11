#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 2010
#define maxm 4000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct edge
{
    int u,v,next;
    ll c;
}e[2*maxm+5];
int p[maxn+5],d[maxn+5],q[maxn+5],cnt,src,sink;
int cur[maxn+5];
void addedge(int u,int v,ll c)
{
    e[cnt].u=u;e[cnt].v=v;e[cnt].c=c;
    e[cnt].next=p[u];p[u]=cnt++;
    e[cnt].u=v;e[cnt].v=u;e[cnt].c=0;
    e[cnt].next=p[v];p[v]=cnt++;
}
int bfs()
{
    memset(d,-1,sizeof d);
    q[0]=src;
    d[src]=0;
    int rear=0;
    rep(front,0,rear)
    {
        int u=q[front];
        for(int i=p[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].c>0 && d[v]==-1)
            {
                d[v]=d[u]+1;
                q[++rear]=v;
            }
        }
    }
    return d[sink]!=-1;
}
ll dfs(int now,ll f)
{
    if(now==sink) return f;
    ll r=0;
    for(int i=cur[now];i!=-1 && r<f;i=e[i].next)
    {
        int v=e[i].v;
        if(e[i].c>0 && d[v]==d[now]+1)
        {
            ll tmp=min(f-r,e[i].c);
            ll x=dfs(v,tmp);
            r+=x;
            e[i].c-=x;
            e[i^1].c+=x;
            cur[now]=i;
        }
    }
    if(r!=f) d[now]=-2;
    return r;
}
ll max_flow(int n)
{
    ll flow=0;
    while(bfs())
    {
        rep(i,1,n) cur[i]=p[i];
        flow+=dfs(src,inf);
    }
    return flow;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    src=n+m+1;
    sink=n+m+2;
    ll ans=0;
    cnt=0;
    memset(p,-1,sizeof p);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        addedge(i,sink,x);
    }
    rep(i,1,m)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ans+=w;
        addedge(src,i+n,w);
        addedge(i+n,u,inf);
        addedge(i+n,v,inf);
    }
    printf("%I64d\n",ans-max_flow(n+m+2));
    return 0;
}