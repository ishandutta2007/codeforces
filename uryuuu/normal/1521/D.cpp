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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const ll Mod=998244353;


vector<int>g[maxn],h[maxn];
struct node
{
    int u,v;
    node(int _u=0,int _v=0)
    {
        u=_u;
        v=_v;
    }
}ans1[maxn],ans2[maxn];
int cnt1=0,cnt2=0;
int d[maxn];

int fa[maxn];

int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}

int del[maxn];

void dfs(int u,int f)
{
    for(int v:g[u])
    {
        if(v==f)
            continue;
        dfs(v,u);
    }
    int sum=d[u]-2;
    int fu,fv;
    if(sum>0&&f!=0)
    {
        sum--;
        del[u]=1;
        d[u]--;
        d[f]--;
    }
  
    for(int v:g[u])
    {
        if(v==f)
            continue;
        if(del[v])
        {
            ans1[++cnt1]=node(u,v);
            continue;
        }
        if(sum>0)
        {
            sum--;
            ans1[++cnt1]=node(u,v);
            d[u]--;
            d[v]--;
        }
        else
        {
            fu=findx(u);
            fv=findx(v);
            if(fu<fv)
                swap(fu,fv);
            fa[fu]=fv;
        }
    }
}


int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        int u,v;
        cin>>n;
        cnt1=0;cnt2=0;
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            g[i].clear();
            h[i].clear();
            fa[i]=i;
            del[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1)
            {
                h[findx(i)].push_back(i);
            }
            else if(d[i]==0)
            {
                h[findx(i)].push_back(i);
                h[findx(i)].push_back(i);
            }
        }
        int L=0;
        int sz;
        int lson,rson;
        for(int i=2;i<=n;i++)
        {
            sz=h[i].size();
            if(sz==0)
                continue;
            lson=h[i][0];
            rson=h[i][sz-1];
            ans2[++cnt2]=node(h[1][L],lson);
            h[1].push_back(rson);
            L++;
        }
        cout<<cnt1<<endl;
        for(int i=1;i<=cnt1;i++)
        {
            cout<<ans1[i].u<<' '<<ans1[i].v<<' '<<ans2[i].u<<' '<<ans2[i].v<<endl;
        }
    }
    
    return 0;
}

/*
 1
 31
 21 5
 27 14
 30 2
 22 31
 24 2
 31 10
 31 21
 9 19
 7 14
 3 27
 28 31
 15 6
 13 7
 11 26
 7 29
 30 18
 13 9
 4 15
 25 10
 19 23
 17 18
 1 23
 25 11
 20 2
 15 16
 18 13
 13 10
 8 21
 19 4
 12 9
 */