#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 3000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;


typedef int flow_t;
const flow_t MF = inf;

struct E
{
    int u,v; flow_t c;
    E(){}
    E(int u,int v,flow_t c):u(u),v(v),c(c){}
};
//Clear when initializing.
vector<E> e;
vi to[maxn+5];

int d[maxn+5],src,sink,cur[maxn+5];

void add(int u,int v,flow_t c)
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
flow_t dfs(int now,flow_t f)
{
    if(now==sink) return f;
    int r=0,l=to[now].size();
    for(int &id=cur[now];id<l;id++)
    {
        int i=to[now][id],v=e[i].v;
        if(e[i].c>0 && d[v]==d[now]+1)
        {
            flow_t tmp=min(f-r,e[i].c);
            flow_t x=dfs(v,tmp);
            r+=x;
            e[i].c-=x;
            e[i^1].c+=x;
        }
        if(r==f) break;
    }
    return r;
}
flow_t maxflow(int n)
{
    flow_t flow=0;
    while(bfs(n))
    {
        rep(i,1,n) cur[i]=0;
        flow+=dfs(src,inf);
    }
    return flow;
}

int a[maxn+5],b[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    int N=n,S=0; src=++N, sink=++N;
    rep(i,1,n) if(b[i]>=0) S+=b[i],add(src,i,b[i]); else add(i,sink,-b[i]);
    rep(i,1,n) 
    {
        vi mark(101,0);
        per(j,1,i-1) if(a[i]%a[j]==0 && mark[a[j]]==0) mark[a[j]]=1, add(i,j,inf);
    }
    printf("%d\n",S-maxflow(N));
    return 0;
}