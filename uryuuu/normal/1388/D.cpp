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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  
ll a[maxn];
int b[maxn],fa[maxn];
vector<int>g[maxn];
int vis[maxn];
int tim[maxn];
int cnt=0;
int m=0;
int c[maxn];


void dfs(int u,int fa)
{
    for(int j=0;j<g[u].size();j++)
    {
        int v=g[u][j];
        if(v==fa)
            continue;
        dfs(v,u);
        if(a[v]<0)
        {
            vis[v]=1;
            tim[cnt--]=v;
            continue;
        }
        a[u]+=a[v];
    }
}

void dfs2(int u,int fa)
{
    for(int j=0;j<g[u].size();j++)
    {
        int v=g[u][j];
        if(v==fa)
            continue;
        if(vis[v])
            continue;
        dfs2(v,u);
    }
    c[++m]=u;
}


int main()
{
    sync;
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=-1)
            g[b[i]].push_back(i);
    }
    cnt=n;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==-1)
        {
            dfs(i,0);
            tim[cnt--]=i;
        }
    }
    
    for(int i=cnt+1;i<=n;i++)
    {
        dfs2(tim[i],0);
//        cout<<tim[i]<<' ';
    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<vis[i]<<' ';
//    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        ans=1ll*ans+1ll*a[i];
    }
    
    
//    for(int i=1;i<=n;i++)
//        cout<<fa[i]<<' ';
//    cout<<endl;
//    a[0]=0;
//    int id,preid;
//    int m=0;
//    for(int i=1;i<=n;i++)
//    {
//        if(fa[i]==i)
//        {
//            int cnt=1;
//            c[1]=i;
//            while(b[c[cnt]]!=-1)
//            {
//                c[cnt+1]=b[c[cnt]];
//                cnt++;
//            }
//            int l=1,preid=0;
//            for(int j=2;j<=cnt;j++)
//            {
//                id=c[j];
//                a[id]+=a[preid];
//                if(a[id]<0)
//                {
//                    vis[id]=1;
//                    preid=0;
//                    for(int k=l;k<=j;k++)
//                    {
//                        g[id].push_back(c[k]);
//                    }
//                    l=j+1;
//                    continue;
//                }
//                preid=id;
//            }
//            if(vis[c[cnt]]==0)
//            {
//                for(int k=l;k<=cnt;k++)
//                {
//                    g[c[cnt]].push_back(c[k]);
//                }
//            }
//            for(int j=cnt;j>=1;j--)
//            {
//                if(vis[c[j]])
//                {
//                    for(int k=0;k<g[c[j]].size();k++)
//                    {
//                        st[++m]=g[c[j]][k];
//                    }
//                }
//            }
//        }
//    }
//    for(int i=1;i<=n;i++)
//    {
//        ans=1ll*ans+1ll*a[i];
//    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<c[i]<<' ';
    cout<<endl;
    return 0;
}