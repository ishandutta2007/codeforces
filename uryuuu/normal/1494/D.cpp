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

int a[505][505];
int fa[maxn];
int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}
int c[maxn];

struct node
{
    int u,v,w;
}b[maxn];

bool cmp(node a,node b)
{
    if(a.w==b.w)
    {
        if(a.u==b.u)
            return a.v<b.v;
        return a.u<b.u;
    }
    return a.w<b.w;
}
int g[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
        c[i]=a[i][i];
    }
    for(int i=1;i<maxn;i++)
        fa[i]=i;
    
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            b[++cnt].u=i;
            b[cnt].v=j;
            b[cnt].w=a[i][j];
        }
    }

    int k=n;
    int fu,fv,w;
    sort(b+1,b+cnt+1,cmp);
    int mx;
    for(int i=1;i<=cnt;i++)
    {
        u=b[i].u;
        v=b[i].v;
        w=b[i].w;
        fu=findx(u);
        fv=findx(v);
        if(fu==fv)
        {
            continue;
        }
        mx=max(c[fu],c[fv]);
        if(mx==w)
        {
            if(c[fu]==w)
            {
                g[fv]=fu;
                fa[fv]=fu;
            }
            else
            {
                g[fu]=fv;
                fa[fu]=fv;
            }
        }
        else if(mx<w)
        {
            c[++k]=w;
            g[fu]=k;
            g[fv]=k;
            fa[fu]=k;
            fa[fv]=k;
        }
    }
    cout<<k<<endl;
    for(int i=1;i<=k;i++)
        cout<<c[i]<<' ';
    cout<<endl;

    for(int i=1;i<=k;i++)
    {
        if(findx(i)==i)
        {
            cout<<i<<endl;
            break;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(findx(i)!=i)
            cout<<i<<' '<<g[i]<<endl;
    }
    return 0;
}