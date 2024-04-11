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
//#include<unordered_map>
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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn =500010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


int vis[maxn],ans[maxn],b[maxn],val[maxn];
vector<int>g[maxn];
vector<int>h[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        h[b[i]].push_back(i);
    }
    int f=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int v:h[i])
        {
            ans[++cnt]=v;
        }
    }

    for(int i=1;i<=n;i++)
    {
        u=ans[i];
        val[u]++;
        if(val[u]!=b[u])
        {
            f=1;
            break;
        }
        for(int v:g[u])
        {
            if(val[v]+1==val[u])
                val[v]++;
        }
    }
    
    
    if(f)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    
    return 0;
}