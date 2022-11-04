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


int n, ma, root,k;
int anc[maxn][22];
vector<pii>g[maxn];
int dfn[maxn];
int tot=0;
int d[maxn];
ll dis[maxn];

inline void dfs(int u,int dep,ll len,int fa)
{
    dfn[u]=++tot;
    d[u]=dep;
    dis[u]=len;
    anc[u][0]=fa;
    int v;
    ll w;
    for(auto f:g[u])
    {
        v=f.first;
        w=f.second;
        if(v==fa)
            continue;
        dfs(v,dep+1,len+w,u);
    }
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
    dfs(root, 0,0, 0);
    for (int j = 1;j<=20;j++)
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
ll sum;

ll gtdis(int x,int y)
{
    return dis[x]+dis[y]-2*dis[lca(x,y)];
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
        sum+=gtdis(x,*--st.end())+gtdis(x,*it)-gtdis(*it,*--st.end());
    }
    else if(it==--st.end())
    {
        --it;
        sum+=gtdis(x,*st.begin())+gtdis(x,*it)-gtdis(*it,*st.begin());
    }
    else
    {
        IT=it;
        ++IT;
        --it;
        sum+=gtdis(*it,x)+gtdis(*IT,x)-gtdis(*it,*IT);
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
        sum-=gtdis(x,*--st.end())+gtdis(x,*it)-gtdis(*it,*--st.end());
    }
    else if(it==--st.end())
    {
        --it;
        sum-=gtdis(x,*st.begin())+gtdis(x,*it)-gtdis(*it,*st.begin());
    }
    else
    {
        IT=it;
        ++IT;
        --it;
        sum-=gtdis(*it,x)+gtdis(*IT,x)-gtdis(*it,*IT);
    }
    st.erase(x);
}



int main()
{
    int u,v;
    ll w;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(mkp(v,w));
        g[v].push_back(mkp(u,w));
    }
    root=1;
    init();

    int q;
    cin>>q;
    sum=0;
    while(q--)
    {
        char op;
        cin>>op;
        if(op=='+')
        {
            cin>>u;
            ins(u);
        }
        else if(op=='-')
        {
            cin>>u;
            del(u);
        }
        else
            cout<<sum/2ll<<endl;
    }
    return 0;
}