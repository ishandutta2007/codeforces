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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=20005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int n,m,k;
int a[60][maxn],sum[60][maxn],dp[60][maxn];

int mx[maxn<<2],lazy[maxn<<2];

void pushup(int rt)
{
    mx[rt]=max(mx[lr],mx[rr]);
}

void pushdown(int rt)
{
    if(lazy[rt])
    {
        mx[lr]+=lazy[rt];
        mx[rr]+=lazy[rt];
        lazy[lr]+=lazy[rt];
        lazy[rr]+=lazy[rt];
        lazy[rt]=0;
    }
}

void build(int rt,int l,int r)
{
    lazy[rt]=0;
    mx[rt]=0;
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
}

void update(int rt,int l,int r,int L,int R,int val)
{
    if(l>R||r<L)
    {
        return;
    }
    if(l>=L&&r<=R)
    {
        lazy[rt]+=val;
        mx[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    update(lr,l,mid,L,R,val);
    update(rr,mid+1,r,L,R,val);
    pushup(rt);
    return;
}

int query(int rt,int l,int r,int L,int R)
{
    if(l>R||r<L)
        return 0;
    if(l>=L&&r<=R)
    {
        return mx[rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    return max(query(lr,l,mid,L,R),query(rr,mid+1,r,L,R));
}

int getsum(int i,int j)
{
    int ret=sum[i][j+k-1]-sum[i][j-1];
    if(i!=n)
    {
        ret+=sum[i+1][j+k-1]-sum[i+1][j-1];
    }
    return ret;
}

int main()
{
    sync;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+a[i][j];
    }
    for(int i=1;i<=m-k+1;i++)
        dp[1][i]=getsum(1,i);
    for(int i=2;i<=n;i++)
    {
        build(1,1,m-k+1);
        for(int j=1;j<=m-k+1;j++)
            update(1,1,m-k+1,j,j,dp[i-1][j]);
        for(int j=1;j<=m-k+1;j++)
        {
            int l=max(j,1),r=min(j+k-1,k);
            if(l<=r)
                update(1,1,m-k+1,j,j,-(sum[i][r]-sum[i][l-1]));
        }
        for(int j=1;j<=m-k+1;j++)
        {
            dp[i][j]=mx[1]+getsum(i,j);
            int L=max(1,j-k+1);
            int R=min(m-k+1,j);
            update(1,1,m-k+1,L,R,a[i][j]);
            if(j!=m-k+1)
            {
                int L=max(1,j+1);
                int R=min(m-k+1,j+k);
                update(1,1,m-k+1,L,R,-a[i][j+k]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m-k+1;i++)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}