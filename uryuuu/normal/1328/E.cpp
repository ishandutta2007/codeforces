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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


int n, ma, root;
int d[maxn],anc[maxn][25];
vector<int>g[maxn];
inline void dfs(int u,int dep,int fa)
{
    d[u]=dep;
    anc[u][0]=fa;
    ma=max(ma,dep);
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
    int s = log2(ma);
    for (int j = 1;j<= s;j++)
        for(int i = 1;i<=n;i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
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


int b[maxn];

bool cmp(int a,int b)
{
    return d[a]>d[b];
}

int main()
{
    sync;
    int m;
    cin>>n>>m;
    int u,v;
    rep(i,2,n)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root=1;
    init();
    int k;
    while(m--)
    {
        cin>>k;
        rep(i,1,k)
        {
            cin>>b[i];
        }
        sort(b+1,b+k+1,cmp);
        int f=0;
        int zx=b[1];    //lca
        for(int i=2;i<=k;i++)
        {
            int w=query(zx,b[i]);   //lca
            if(d[zx]-d[w]>1&&d[b[i]]-d[w]>1)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}