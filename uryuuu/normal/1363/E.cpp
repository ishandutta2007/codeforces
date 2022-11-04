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
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int siz[maxn];
int x;
ll a[maxn];
int b[maxn];
int c[maxn];
vector<int>g[maxn];
int b1[maxn],b0[maxn];

ll ans=0;

void dfs(int u,int fa,ll mn)
{
    b1[u]=0;
    if(b[u]==0&&c[u]==1)
        b1[u]++;
    b0[u]=0;
    if(c[u]==0&&b[u]==1)
        b0[u]++;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u,min(a[u],mn));
        b1[u]+=b1[v];
        b0[u]+=b0[v];
    }
    ll zx=min(a[u],mn);
    ll d=min(b1[u],b0[u]);
    ans+=2ll*d*zx;
    b1[u]-=d;
    b0[u]-=d;
}


 
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    int u,v;
    int bb1=0,cc1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]==1)
            bb1++;
        if(c[i]==1)
            cc1++;
    }
    if(bb1!=cc1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1ll*2e17);
    cout<<ans<<endl;
    
    return 0;
}