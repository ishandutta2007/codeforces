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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>g[maxn];
ll a[maxn],b[maxn];
vector<int>d[maxn];
int dep[maxn];
int f[maxn];

void dfs(int u,int fa)
{
    f[u]=fa;
    dep[u]=dep[fa]+1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
    }
}

bool cmp(int u,int v)
{
    return a[u]>a[v];
}


ll sub[maxn],add[maxn],son[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n,x;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            d[i].clear();
            son[i]=0;
            add[i]=-2e18;
            sub[i]=-2e18;
            b[i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            cin>>x;
            g[x].push_back(i);
            g[i].push_back(x);
        }
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1,0);
        int lmt=0;
        for(int i=2;i<=n;i++)
        {
            lmt=max(lmt,dep[i]);
            d[dep[i]].push_back(i);
        }
        int L,R;
        for(int i=lmt;i>=2;i--)
        {
            sort(d[i].begin(),d[i].end(),cmp);
            L=d[i][0];
            R=d[i][d[i].size()-1];
            for(int u:d[i])
            {
                b[u]=max(abs(a[u]-a[L]),abs(a[u]-a[R]))+son[u];
                b[u]=max(b[u],a[u]+sub[i]);
                b[u]=max(b[u],-a[u]+add[i]);
                son[f[u]]=max(son[f[u]],b[u]);
                sub[i-1]=max(sub[i-1],-a[f[u]]+b[u]);
                add[i-1]=max(add[i-1],a[f[u]]+b[u]);
            }
        }
        cout<<son[1]<<endl;
    }
    
    return 0;
}