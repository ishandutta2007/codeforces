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
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

vector<pii>g[maxn];

struct node
{
    int u,mn,mx;
    ll w;
    node (int u1=0,int mn1=0,int mx1=0,ll w1=0)
    {
        u=u1;
        mn=mn1;
        mx=mx1;
        w=w1;
    }
    bool operator<(const node&b)const
    {
        return w>b.w;
    }
};

ll dis[maxn][2][2];
priority_queue<node>q;
bool vis[maxn][2][2];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    ll w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(mkp(v,w));
        g[v].push_back(mkp(u,w));
    }
    for(int i=1;i<=n;i++)
    {
        rep(j,0,1)
        rep(k,0,1)
        dis[i][j][k]=2e18;
    }
    dis[1][0][0]=0;
    q.push(node(1,0,0,0));
    int mn,mx;
    ll W;
    while(q.size())
    {
        node a=q.top();
        u=a.u;
        mn=a.mn;
        mx=a.mx;
        w=a.w;
        q.pop();
        if(w>dis[u][mn][mx])
            continue;
        if(vis[u][mn][mx])
            continue;
        vis[u][mn][mx]=1;
//        cout<<u<<' '<<mn<<' '<<mx<<' '<<w<<' '<<dis[u][mn][mx]<<' '<<dis[u][1][1]<<endl;
        for(auto f:g[u])
        {
            v=f.first;
            W=f.second;
            if(dis[v][mn][mx]>dis[u][mn][mx]+W)
            {
                dis[v][mn][mx]=dis[u][mn][mx]+W;
                q.push(node(v,mn,mx,dis[v][mn][mx]));
            }
            
            if(mn==0)
            {
                if(dis[v][1][mx]>dis[u][mn][mx]+2*W)
                {
                    dis[v][1][mx]=dis[u][mn][mx]+2*W;
                    q.push(node(v,1,mx,dis[v][1][mx]));
                }
            }
            
            if(mx==0)
            {
                if(dis[v][mn][1]>dis[u][mn][mx])
                {
                    dis[v][mn][1]=dis[u][mn][mx];
                    q.push(node(v,mn,1,dis[v][mn][1]));
                }
            }
        }
        
    }
    for(int i=2;i<=n;i++)
    {
        cout<<min(dis[i][1][1],dis[i][0][0])<<' ';
    }
    cout<<endl;
    return 0;
}