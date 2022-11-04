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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

int c[maxn];
vector<int>g[maxn];

int head[maxn],d[maxn];
int tot,n,m;
struct node
{
    int v,nxt;
    ll w;
}e[400005];

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

int a[maxn],b[maxn];
bool vis[200];

int main()
{
    sync;
    memset(head,-1,sizeof(head));
    int st,ed;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    rep(i,1,n)
    cin>>b[i];
    st=0;
    ed=n+1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]<0)
            add(i,ed,-b[i]);
        else
        {
            add(st,i,b[i]);
            ans+=b[i];
        }
        mm(vis);
        for(int j=i-1;j>=1;j--)
        {
            if(vis[a[j]]==0&&a[i]%a[j]==0)
            {
                add(i,j,2e9);
                vis[a[j]]=1;
            }
        }
    }
   
    tot=0;
    cout<<ans-dinic(st,ed)<<endl;

    return 0;
}