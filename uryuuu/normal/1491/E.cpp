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
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int FIB[maxn],fib[maxn];
int nxt[maxn][2];
vector<int>g[maxn];

unordered_map<int,int>mp[maxn];

int siz[maxn];
vector<int>q;
int Fa[maxn];

void dfs2(int u,int fa)
{
    q.push_back(u);
    Fa[u]=fa;
    siz[u]=1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        if(mp[u][v])
            continue;
        dfs2(v,u);
        siz[u]+=siz[v];
    }
}


int dfs(int u,int fa)
{
    q.clear();
    dfs2(u,0);
    if(siz[u]==1)
        return 1;
    for(int v:q)
    {
        if(v==u)
            continue;
//        cout<<siz[u]<<' '<<v<<' '<<siz[v]<<endl;
        if(siz[v]==nxt[siz[u]][0]||siz[v]==nxt[siz[u]][1])
        {
//            cout<<siz[u]<<' '<<v<<' '<<siz[v]<<endl;
            mp[v][Fa[v]]=1;
            mp[Fa[v]][v]=1;
//            cout<<u<<' '<<dfs(u,0)<<' '<<v<<' '<<dfs(v,0)<<endl;
            return dfs(u,0)&&dfs(v,0);
        }
    }
    return 0;
}

signed main()
{
    sync;
    int n;
    cin>>n;
    FIB[0]=1;
    FIB[1]=1;
    for(int i=2;i<=10000;i++)
    {
        FIB[i]=FIB[i-1]+FIB[i-2];
        if(FIB[i]>200000)
            break;
        fib[FIB[i]]=1;
        nxt[FIB[i]][0]=FIB[i-1];
        nxt[FIB[i]][1]=FIB[i-2];
//        cout<<FIB[i]<<endl;
    }
    fib[1]=1;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(fib[n]==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(dfs(1,0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}