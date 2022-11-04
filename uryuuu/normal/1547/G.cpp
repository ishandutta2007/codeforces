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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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

stack<int>s;
int low[maxn],dfn[maxn],vis[maxn],cnt;
int col[maxn],hf[maxn],sum[maxn];
int tot;

void tarjan(int u)
{
//    cout<<u<<' '<<fa<<endl;
    dfn[u]=low[u]=++cnt;
    s.push(u);
    vis[u]=1;
    for(int v:g[u])
    {
//        if(v==fa)
//            continue;
        if(dfn[v]==0)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==1)
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(1)
        {
            int t=s.top();
            s.pop();
            col[t]=tot;
            vis[t]=0;
            if(t==u)
                break;
        }
    }
}

int dp[maxn];
int d[maxn];


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        int u,v;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vis[i]=dfn[i]=low[i]=hf[i]=dp[i]=sum[i]=d[i]=col[i]=0;
            g[i].clear();
            h[i].clear();
        }
        cnt=0;
        tot=0;
        while(s.size())
            s.pop();
        
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }
        
        tarjan(1);
        
        for(int i=1;i<=n;i++)
        {
            sum[col[i]]++;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)
                continue;
            u=i;
            for(int v:g[u])
            {
                if(col[v]!=col[u])
                {
                    h[col[u]].push_back(col[v]);
                    d[col[v]]++;
                }
            }
        }
        
        for(int i=1;i<=tot;i++)
        {
            dp[i]=1;
            if(d[i]>1)
                dp[i]=2;
            if(sum[i]>1)
                dp[i]=3;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)
                continue;
            u=i;
            for(int v:g[u])
            {
                if(u==v)
                    dp[col[u]]=3;
            }
        }
        
        int st=col[1];
        queue<int>q;
        q.push(st);
        while(q.size())
        {
            u=q.front();
            q.pop();
            for(int v:h[u])
            {
                dp[v]=max(dp[u],dp[v]);
                d[v]--;
                if(d[v]==0)
                    q.push(v);
            }
        }
        
//        for(int i=1;i<=n;i++)
//            cout<<col[i]<<' ';
//        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)
                cout<<0<<' ';
            else
            {
                if(dp[col[i]]==3)
                    cout<<-1<<' ';
                else
                    cout<<dp[col[i]]<<' ';
            }
        }
        cout<<endl;
    }
    
    return 0;
}