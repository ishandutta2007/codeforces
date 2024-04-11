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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int vis[maxn];
vector<int>g[maxn];
int ans[maxn];
int f;

void dfs(int u)
{
    int fl=0;
    for(int v:g[u])
    {
        if(vis[v]==1)
        {
            fl=1;
            break;
        }
    }
    if(fl==1)
        vis[u]=2;
    else
        vis[u]=1;
    for(int v:g[u])
    {
        if(vis[v])
        {
            continue;
        }
        dfs(v);
    }
}


int main()
{
    sync;
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
        }
        int u,v;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        f=0;
        vis[1]=1;
        dfs(1);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
//            cout<<i<<' '<<vis[i]<<endl;
            if(vis[i]==1)
            {
                ans[++cnt]=i;
            }
            if(vis[i]==0)
                f=1;
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}