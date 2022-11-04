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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
//typedef pair<pii,int> piii;

vector<int>g[maxn];
int d[maxn];
ll mp[1005][1005];

struct node
{
    int u,v;
    ll w;
    node(int _u=0,int _v=0,ll _w=0)
    {
        u=_u;
        v=_v;
        w=_w;
    }
}ans[maxn];

int cnt=0;
int rt;

struct nod
{
    int u,v;
    ll w;
}e[maxn];

int dfs(int u,int fa)
{
    if(d[u]==1)
        return u;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        return dfs(v,u);
    }
    return 0;
}

int lv1[maxn],lv2[maxn];

int main()
{
    sync;
    int n;
    int u,v;
    ll w;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        d[u]++;
        d[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[u][v]=w;
        mp[v][u]=w;
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cnt=0;
    
    int rt,m;
    for(int i=1;i<n;i++)
    {
        u=e[i].u;
        v=e[i].v;
        w=e[i].w;
        if(d[u]>d[v])
            swap(u,v);
        if(d[u]==1&&d[v]==1)
        {
            ans[++cnt]=node(u,v,w);
        }
        else if(d[u]==1)
        {
            rt=u;
            m=0;
            for(int son:g[v])
            {
                if(son==u)
                    continue;
                lv2[++m]=dfs(son,v);
            }
//            cout<<rt<<' '<<lv2[1]<<' '<<lv2[2]<<endl;
            ans[++cnt]=node(rt,lv2[1],w/2);
            ans[++cnt]=node(rt,lv2[2],w/2);
            ans[++cnt]=node(lv2[1],lv2[2],-w/2);
        }
        else
        {
            m=0;
            for(int son:g[u])
            {
                if(son==v)
                    continue;
                lv1[++m]=dfs(son,u);
//                cout<<son<<' '<<u<<' '<<dfs(son,u)<<endl;
            }
            
            m=0;
            for(int son:g[v])
            {
                if(son==u)
                    continue;
                lv2[++m]=dfs(son,v);
//                cout<<son<<' '<<v<<' '<<dfs(son,v)<<endl;
            }
//            cout<<lv1[1]<<' '<<lv1[2]<<' '<<lv2[1]<<' '<<lv2[2]<<endl;
            ans[++cnt]=node(lv1[1],lv2[1],w/2);
            ans[++cnt]=node(lv1[2],lv2[2],w/2);
            ans[++cnt]=node(lv1[1],lv1[2],-w/2);
            ans[++cnt]=node(lv2[1],lv2[2],-w/2);
        }
        
    }
    cout<<"YES"<<endl;
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<ans[i].u<<' '<<ans[i].v<<' '<<ans[i].w<<endl;
    }
    
    return 0;
}