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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int n,m,k;

ll a[maxn<<2],lazy[maxn<<2];


void build(int rt,int l,int r)//1,n,
{
    a[rt]=0;
    lazy[rt]=0;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
}

void pushdown(int rt)//
{
    if(lazy[rt])
    {
        a[lr]=lazy[rt];
        lazy[lr]=lazy[rt];
        a[rr]=lazy[rt];
        lazy[rr]=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        a[rt]=val;
        lazy[rt]=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
}

int s[maxn];

void query(int rt,int l,int r)
{
    if(l==r)
    {
        s[l]=a[rt];
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    query(lr,l,mid);
    query(rr,mid+1,r);
}

struct Nod
{
    int s,t,d;
    ll w;
}b[maxn];

bool cmp(Nod a,Nod b)
{
    if(a.w==b.w)
    {
        return a.d>b.d;
    }
    return a.w>b.w;
}


ll dp[maxn][210];

int main()
{
    sync;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>b[i].s>>b[i].t>>b[i].d>>b[i].w;
    }
    sort(b+1,b+k+1,cmp);
    
    build(1,1,n);
    for(int i=k;i>=1;i--)
    {
        upd(1,1,n,b[i].s,b[i].t,i);
    }
    
    query(1,1,n);
    
        
    for(int i=2;i<=n+2;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=2e17;
        }
    }
    
    int x,y;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            }
            continue;
        }
        
        x=s[i];
        for(int j=0;j<=m;j++)
        {
            if(dp[i][j]==2e17)
                continue;
            y=b[x].t-i+1;
            if(j>0)
                dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]);
            dp[b[x].d+1][j]=min(dp[b[x].d+1][j],dp[i][j]+b[x].w);
            
        }
    }
    ll zx=2e17;
    for(int j=0;j<=m;j++)
    {
        zx=min(zx,dp[n+1][j]);
    }
    
    cout<<zx<<endl;
    return 0;
}