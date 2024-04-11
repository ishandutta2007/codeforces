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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=305;
const ll Mod=1000000007;
//const ll Mod=998244353;


ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}

int n,root;

int d[maxn],anc[maxn][20];

vector<int>g[maxn];

inline void dfs(int u,int dep,int fa)
{
    d[u]=dep;
    anc[u][0]=fa;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!= fa)
            dfs(g[u][i],dep+1,u);
}

inline int log2(int x)
{
    int k=0;
    while(x>1)
    {
        x>>=1;
        k++;
    }
    return k;
}

inline void init()
{
    dfs(root, 0, 0);
    int s = 10;
    for (int j = 1;j<= s;j++)
        for(int i = 1;i<=n;i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
}
// xyLCA

inline int query(int x,int y)
{
    if(d[x]<d[y])
        swap(x, y);
    int s = log2(d[x] - d[y]);
    while(d[x]>d[y])
    {
        if(d[x]-(1<<s)>=d[y])
            x=anc[x][s];
        s--;
    }
    s=log2(d[x]);
    while(s>-1)
    {
        if (anc[x][s]!=anc[y][s])
        {
            x=anc[x][s];
            y=anc[y][s];
        }
        s--;
    }
    return x==y?x:anc[x][0];
}


ll p[maxn],inv[maxn];

ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

ll dp[maxn][maxn];

int main()
{
    p[0]=inv[0]=1ll;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;

    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++)
        dp[0][i]=1ll;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])*inv[2]%Mod;
        }
    }
    
    ll ans=0ll;
    int ac;
    ll wu,wv;
    ll p,q;
    for(int k=1;k<=n;k++)
    {
        root=k;
        init();
//        for(int i=1;i<=n;i++)
//        {
//            cout<<root<<' '<<i<<' '<<anc[i][0]<<' '<<anc[i][1]<<endl;
//        }
        for(u=1;u<=n;u++)
        {
            for(v=u+1;v<=n;v++)
            {
                ac=query(u,v);
//                cout<<root<<' '<<u<<' '<<v<<' '<<ac<<endl;
                if(ac==u)
                    continue;
                if(ac==v)
                {
                    ans=(ans+1ll)%Mod;
                    continue;
                }
                wu=d[u]-d[ac];
                wv=d[v]-d[ac];
                ans=(1ll*ans+dp[wv][wu])%Mod;
            }
        }
    }
    ans=ans*ksm(n,Mod-2)%Mod;
    cout<<(ans%Mod+Mod)%Mod<<endl;
    
    return 0;
}