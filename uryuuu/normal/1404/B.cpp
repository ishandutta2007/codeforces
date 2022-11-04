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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

vector<int>g[maxn];
int dep[maxn];
int pos,mx;

void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    if(dep[u]>mx)
    {
        mx=dep[u];
        pos=u;
    }
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
    }
}

int main()
{
    sync;
    int t;
    int n,a,b,da,db;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            dep[i]=0;
        }
        dep[0]=-1;
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        pos=a;
        mx=0;
        dfs(a,0);
        int f=0;
        if(dep[b]<=da||2*da>=db)
        {
            f=1;
        }
        mx=0;
        dfs(pos,0);
        if(2*da>=mx)
        {
            f=1;
        }
        if(f)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;
        
        
    }
    
    return 0;
}