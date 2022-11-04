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
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
 

vector<int>g[maxn];
struct node
{
    int d,u,v;
}h[maxn];
int d[maxn];
int dep[maxn];
int cnt=1;
int vis[maxn];

//int dfs(int u,int fa)
//{
//    if(dep[u]==0)
//        dep[u]=cnt++;
//    vis[u]=1;
//    for(int i=0;i<g[u].size();i++)
//    {
//        int v=g[u][i];
//        if(dep[v]&&dep[v]<dep[u])
//        {
//            cout<<v<<' '<<u<<' '<<dep[v]<<' '<<dep[u]<<endl;
//            return 1;
//        }
//        if(dfs(v,u))
//        {
//            return 1;
//        }
//    }
//    return 0;
//}
//


int main()
{
    sync;
    int t;
    int n;
    int m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            d[i]=0;
            dep[i]=0;
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>h[i].d>>h[i].u>>h[i].v;
            if(h[i].d==1)
            {
                g[h[i].u].push_back(h[i].v);
                d[h[i].v]++;
            }
        }
        int f=0;
        queue<int>q;
        
        for(int i=1;i<=n;i++)
        {
            if(d[i]==0)
                q.push(i);
        }
        
        cnt=1;
        int u,v;
        
        while(q.size())
        {
            u=q.front();
            q.pop();
            dep[u]=cnt++;
//            cout<<u<<endl;
            for(int i=0;i<g[u].size();i++)
            {
                v=g[u][i];
                if(vis[v])
                    continue;
                d[v]--;
                if(d[v]<=0)
                {
                    q.push(v);
                }
            }
        }
        
        if(cnt!=n+1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=m;i++)
            {
                if(h[i].d==1)
                {
                    cout<<h[i].u<<' '<<h[i].v<<endl;
                }
                else
                {
                    if(dep[h[i].u]<dep[h[i].v])
                        cout<<h[i].u<<' '<<h[i].v<<endl;
                    else
                        cout<<h[i].v<<' '<<h[i].u<<endl;
                }
            }
        }
        
    }
    return 0;
}