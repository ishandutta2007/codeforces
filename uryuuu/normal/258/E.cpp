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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

vector<int>g[maxn],q[maxn];
int dfn[maxn],ed[maxn];
int cnt,tot;
int root[maxn];
int ans[maxn];
int n,m;
struct node
{
    int sum,lson,rson,lazy;
}tr[maxn*60];

void dfs(int u,int fa)
{
    dfn[u]=++tot;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
    }
    ed[u]=tot;
}

void upd(int l,int r,int pre,int &now,int L,int R)
{
    tr[now=++cnt]=tr[pre];
    if(r<L||l>R)
        return;
    if(tr[now].lazy)
        return;
    if(L<=l&&r<=R)
    {
        tr[now].lazy=1;
        tr[now].sum=r-l+1;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=L)
        upd(l,mid,tr[pre].lson,tr[now].lson,L,R);
    if(mid+1<=R)
        upd(mid+1,r,tr[pre].rson,tr[now].rson,L,R);
    tr[now].sum=tr[tr[now].lson].sum+tr[tr[now].rson].sum;
}

void dfs2(int u,int fa)
{
    root[u]=root[fa];
    int tmp;
    for(int v:q[u])
    {
        tmp=root[u];
        upd(1,n,tmp,root[u],dfn[v],ed[v]);
    }
    ans[u]=max(0,tr[root[u]].sum-1);
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs2(v,u);
    }
}


int main()
{
    sync;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        q[u].push_back(u);
        q[u].push_back(v);
        q[v].push_back(u);
        q[v].push_back(v);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
   
    return 0;
}