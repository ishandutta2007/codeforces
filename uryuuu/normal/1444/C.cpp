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
const int maxn=1000010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

struct Node
{
    int u,v,fa,rk;
    bool ds;
    Node(int _u=0,int _v=0,int _fa=0,int _rk=0,bool _ds=0)
    {
        u=_u; v=_v; fa=_fa; rk=_rk; ds=_ds;
    }
}st[maxn];
int top;
struct UFS
{
    int fa[maxn],rk[maxn],c;
    bool ds[maxn];
    void init(int n)
    {
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;
            rk[i]=0;
            ds[i]=0;
        }
    }
    int unite(int u,int v)
    {
        bool du=0,dv=0;
        //printf("uin\n");
        while(u!=fa[u])
        {
            du^=ds[u];
            u=fa[u];
        }
        while(v!=fa[v])
        {
            dv^=ds[v];
            v=fa[v];
        }
        //printf("uot\n");
        if(u==v)
            return du^dv;
        if(rk[u]<rk[v])
        {
            swap(u,v);
            swap(du,dv);
        }
        st[++top]=Node(u,v,fa[v],rk[u],ds[v]);
        fa[v]=u;
        ds[v]=du^dv^1;
        if(rk[u]==rk[v])
            rk[u]++;
        return 2;
    }
    void undo(int t)
    {
        while(t--)
        {
            Node &o=st[top];
            --top;
            fa[o.v]=o.fa;
            ds[o.v]=o.ds;
            rk[o.u]=o.rk;
        }
    }
}ufs;

int n,m,k,c[maxn];

struct edge
{
    int x,y;
    bool operator < (const edge &r)const
    {
        if(c[x]!=c[r.x])
            return c[x]<c[r.x];
        return c[y]<c[r.y];
    }
    bool operator == (const edge &r)const
    {
        return c[x]==c[r.x]&&c[y]==c[r.y];
    }
}e[maxn];
bool nt[maxn];
int main()
{
    sync;
    cin>>n>>m>>k;
    ufs.init(n);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].x>>e[i].y;
        if(c[e[i].x]==c[e[i].y])
        {
            if(nt[c[e[i].x]]==0)
            {
                if(ufs.unite(e[i].x,e[i].y)==0)
                {
                    nt[c[e[i].x]]=1;
                    k--;
                }
            }
            i--;
            m--;
        }
        else if(c[e[i].x]>c[e[i].y])
        {
            swap(e[i].x,e[i].y);
        }
    }
    sort(e+1,e+m+1);
    ll ans=1ll*k*(k-1)/2;
    for(int i=1,j=1;i<=m;i=j)
    {
        int cnt=0,op,flg=nt[c[e[i].x]]|nt[c[e[i].y]];
        while(j<=m&&e[j]==e[i])
        {
            if(flg==0)
            {
                op=ufs.unite(e[j].x,e[j].y);
                if(op==0)
                {
                    flg=1;
                    ans--;
                }
                else if(op==2)
                {
                    cnt++;
                }
            }
            j++;
        }
        ufs.undo(cnt);
    }
    cout<<ans<<endl;
    return 0;
}