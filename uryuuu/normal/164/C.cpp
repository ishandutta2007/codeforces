#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


const int N = 3005;
const int M = 10010;
const ll INF = 1e18;
struct node
{
    int to,next;
    ll cap,flow,cost;
}e[M];
ll f[M],c[M],cnt;
int head[N],tot,pre[N];
ll dis[N];
bool vis[M];
int n,m,q;
int ct;
void init()
{
    tot=cnt=0;
    for(int i=0;i<=ct+5;++i)
        head[i]=-1;
}
inline int addedge(int u,int v,ll cap,ll cost)
{
    int now=tot;
    e[tot].to=v;
    e[tot].cap=cap;
    e[tot].cost=cost;
    e[tot].flow=0;
    e[tot].next=head[u];
    head[u] = tot++;
    e[tot].to=u;
    e[tot].cap=0;
    e[tot].cost=-cost;
    e[tot].flow=0;
    e[tot].next=head[v];
    head[v] = tot++;
    return now;
}
bool spfa(int s,int t)
{
    queue<int> q;
    for(int i=0;i<=ct+5;++i)
    {
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].cap>e[i].flow&&dis[v]>dis[u]+e[i].cost)
            {
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t]==-1)
        return 0;
    return 1;
}
 
ll MCMF(int s,int t,ll &cost)
{
    ll flow=0;
    cost=0;
    ll precost=0;
    while(spfa(s,t))
    {
        ll Min=INF;
        precost=cost;
        for(int i=pre[t];i!=-1;i=pre[e[i^1].to])
        {
            if(Min>e[i].cap-e[i].flow)
                Min=e[i].cap-e[i].flow;
        }
        for(int i=pre[t];i!=-1;i=pre[e[i^1].to])
        {
            e[i].flow+=Min;
            e[i^1].flow-=Min;
            cost+=e[i].cost*Min;
        }
        f[++cnt]=Min;
        c[cnt]=(cost-precost)/Min;
        flow+=Min;
    }
    return flow;
}

int b[maxn];
int s[maxn],t[maxn],w[maxn];
int id[maxn];

int main()
{
    sync;
    int k;
    cin>>n>>k;
    ct=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>t[i]>>w[i];
        t[i]=s[i]+t[i];
        b[++ct]=s[i];
        b[++ct]=t[i];
    }
    sort(b+1,b+ct+1);
    ct=unique(b+1,b+ct+1)-b-1;
    for(int i=1;i<=n;i++)
    {
        s[i]=lower_bound(b+1,b+ct+1,s[i])-b;
        t[i]=lower_bound(b+1,b+ct+1,t[i])-b;
    }
    int st=0,ed=ct+1;
    init();
    addedge(st,1,k,0);
    addedge(ct,ed,k,0);
    for(int i=1;i<ct;i++)
    {
        addedge(i,i+1,k,0);
    }
    for(int i=1;i<=n;i++)
        id[i]=addedge(s[i],t[i],1,-w[i]);
    ll cost=0;
    MCMF(st,ed,cost);
    for(int i=1;i<=n;i++)
    {
        cout<<e[id[i]].flow<<' ';
    }
    cout<<endl;
    return 0;
}