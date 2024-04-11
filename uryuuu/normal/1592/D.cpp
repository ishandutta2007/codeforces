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
const ll Mod=1000000007;
//const ll Mod=998244353;


vector<int>g[maxn];
int vis[maxn],sz[maxn];
int fl,rt;
int siz;


int cnt;
int b[maxn];
int wson,w[maxn];

void findsz(int u,int fa)
{
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==fa||vis[v])
            continue;
        findsz(v,u);
        sz[u]+=sz[v];
    }
}

void dfs(int u,int fa)
{
    w[u]=0;
    for(int v:g[u])
    {
        if(v==fa||vis[v])
            continue;
        dfs(v,u);
        w[u]=max(w[u],sz[v]);
    }
    w[u]=max(w[u],siz-sz[u]);
    if(w[u]<=siz/2)
    {
        wson=u;
        cnt=0;
        for(int v:g[u])
        {
            if(vis[v])
                continue;
            b[++cnt]=v;
        }
    }
}

bool cmp(int a,int b)
{
    return sz[a]<sz[b];
}

int pt[maxn];
int tot;

void dfs2(int u,int fa)
{
    pt[++tot]=u;
    for(int v:g[u])
    {
        if(v==fa||vis[v])
            continue;
        dfs2(v,u);
    }
}


int main()
{
    sync;
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll mx;
    cout<<'?'<<' '<<n;
    for(int i=1;i<=n;i++)
    {
        cout<<' '<<i;
    }
    cout<<endl;
    cin>>mx;
    rt=1;
    ll L,R;
    int mid;
    int j;
    int l,r;
    while(1)
    {
        findsz(rt,0);
        siz=sz[rt];
//        cout<<siz<<' '<<rt<<endl;
        if(siz==2)
        {
            cout<<"! "<<rt<<' ';
            for(int v:g[rt])
            {
                if(vis[v])
                    continue;
                cout<<v<<endl;
            }
            return 0;
        }
        dfs(rt,0);
        
        for(int i=1;i<=cnt;i++)
        {
            findsz(b[i],wson);
        }
        sort(b+1,b+cnt+1,cmp);
        tot=1;
        pt[1]=wson;
        l=0;
        int sum=0;
        while(sum+sz[b[cnt]]<siz/2)
        {
            l++;
            sum+=sz[b[l]];
        }
        
        for(int i=1;i<=l;i++)
        {
            dfs2(b[i],wson);
        }
        dfs2(b[cnt],wson);
        cout<<"? "<<tot;
        for(j=1;j<=tot;j++)
        {
            cout<<' '<<pt[j];
        }
        cout<<endl;
        cin>>L;
        
        if(L==mx)
        {
            for(int i=l+1;i<cnt;i++)
                vis[b[i]]=1;
        }
        else
        {
            for(int i=1;i<=l;i++)
                vis[b[i]]=1;
            vis[b[cnt]]=1;
        }
        rt=wson;
    }
    
        
    return 0;
}