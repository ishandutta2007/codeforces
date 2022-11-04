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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


int n, ma, root,k;
int d[maxn],anc[maxn][20];
vector<int>g[maxn];
int dfn[maxn];
int tot=0;

inline void dfs(int u,int dep,int fa)
{
    dfn[u]=++tot;
    d[u]=dep;
    anc[u][0]=fa;
    ma=max(ma,dep);
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!= fa)
            dfs(g[u][i],dep+1,u);
}
inline int log2(int x)
{
    int k=0;
    while(x>1)
    {
        x>>=1;
        k++;
    }
    return k;
}
inline void init()
{
    ma=0;
    dfs(root, 0, 0);
    int s = log2(ma);
    for (int j = 1;j<= s;j++)
        for(int i = 1;i<=n;i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
// xyLCA
inline int lca(int x,int y)
{
    if(d[x]<d[y])
        swap(x, y);
    int s = log2(d[x] - d[y]);
    while(d[x]>d[y])
    {
        if(d[x]-(1<<s)>=d[y])
            x=anc[x][s];
        s--;
    }
    s=log2(d[x]);
    while(s>-1)
    {
        if (anc[x][s]!=anc[y][s])
        {
            x=anc[x][s];
            y=anc[y][s];
        }
        s--;
    }
    return x==y?x:anc[x][0];
}


struct cmp
{
    bool operator()(int a,int b)
    {
        return dfn[a]<dfn[b];
    }
};

set<int,cmp>st;
set<int,cmp>::iterator it,IT;
int sum;

int dis(int x,int y)
{
    return d[x]+d[y]-2*d[lca(x,y)];
}

void ins(int x)
{
    if(st.empty())
    {
        st.insert(x);
        return;
    }
    st.insert(x);
    it=st.find(x);
    if(it==st.begin())
    {
        ++it;
        sum+=dis(x,*--st.end())+dis(x,*it)-dis(*it,*--st.end());
    }
    else if(it==--st.end())
    {
        --it;
        sum+=dis(x,*st.begin())+dis(x,*it)-dis(*it,*st.begin());
    }
    else
    {
        IT=it;
        ++IT;
        --it;
        sum+=dis(*it,x)+dis(*IT,x)-dis(*it,*IT);
    }
}

void del(int x)
{
    if(st.size()==1)
    {
        st.clear();
        return;
    }
    it=st.find(x);
    if(it==st.begin())
    {
        ++it;
        sum-=dis(x,*--st.end())+dis(x,*it)-dis(*it,*--st.end());
    }
    else if(it==--st.end())
    {
        --it;
        sum-=dis(x,*st.begin())+dis(x,*it)-dis(*it,*st.begin());
    }
    else
    {
        IT=it;
        ++IT;
        --it;
        sum-=dis(*it,x)+dis(*IT,x)-dis(*it,*IT);
    }
    st.erase(x);
}

int ck(int mid)
{
    st.clear();
    sum=0;
    for(int i=1;i<mid;i++)
    {
        ins(i);
    }
    for(int i=mid;i<=n;i++)
    {
        ins(i);
        if(sum<=k)
            return 1;
        del(i-mid+1);
    }
    return 0;
}


int main()
{
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root=1;
    init();
    int l=1,r=k,mid;
    k=2*(k-1);
    int ans=1;
    while(l<r)
    {
        mid=(l+r)/2;
        if(ck(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid;
    }
    if(ck(l))
        ans=max(ans,l);
    
    cout<<ans<<endl;
    return 0;
}