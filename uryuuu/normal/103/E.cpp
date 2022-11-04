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
const int maxn=605;
//const ll Mod=1000000007;
//const ll Mod=998244353;


int c[maxn];
vector<int>g[maxn];

int head[maxn],d[maxn];
int tot,n,m;
struct node
{
    int v,nxt;
    ll w;
}e[40005];

void add(int u,int v,ll c)
{
    e[tot].v=v;
    e[tot].w=c;
    e[tot].nxt=head[u];
    head[u]=tot++;
    e[tot].v=u;
    e[tot].w=0ll;           //0
    e[tot].nxt=head[v];
    head[v]=tot++;
}

int bfs(int s,int t)
{
    queue<int>q;
    memset(d,-1,sizeof(d));
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==t)
            return 1;
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            int v=e[i].v;
            if(d[v]==-1&&e[i].w>0)
            {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return 0;
}


ll dfs(int u,ll flow,int t)
{
    if(u==t)
        return flow;
    ll sum=0;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].v;
        ll w=e[i].w;
        if(w>0&&d[v]==d[u]+1)
        {
            ll tmp=dfs(v,min(1ll*flow-sum,e[i].w),t);
            e[i].w-=1ll*tmp;
            e[i^1].w+=1ll*tmp;
            sum+=1ll*tmp;
            if(sum==flow)
                return sum;
        }
    }
    if(sum==0)
        d[u]=0;
    return sum;
}

ll dinic(int s,int t)
{
    ll total=0;
    while(bfs(s,t))
        total+=1ll*dfs(s,2e14,t);
    return total;
}


int main()
{
    memset(head,-1,sizeof(head));
    int n,m;
    cin>>n;
    int u,v;
    int st,ed;
    st=0;
    ed=n+n+1;
    ll w;
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        while(k--)
        {
            cin>>u;
            add(i,u+n,inf);
        }
    }
    ll ans=0ll;
    for(int i=1;i<=n;i++)
    {
        cin>>w;
        add(st,i,1e8-w);
        ans+=1ll*(1e8-w);
        add(i+n,ed,1e8);
    }
    
    tot=0;
    cout<<min(0ll,-(ans-dinic(st,ed)))<<endl;
    
    return 0;
}