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
//#include <chrono>
//#include <random>
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
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll h[maxn];
ll a[maxn<<2];
ll dp[maxn];
int st[maxn];
int pre[maxn];
ll b[maxn],lazy[maxn<<2];


void pushup(int rt)
{
    a[rt]=max(a[lr],a[rr]);
}

void build(int rt,int l,int r)//1,n,
{
    a[rt]=0;
    lazy[rt]=0;
    if(l==r)
    {
        a[rt]=-2e18;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}

void pushdown(int rt)//
{
    if(lazy[rt])
    {
        a[lr]=max(a[lr],a[rt]);
        lazy[lr]=1;
        a[rr]=max(a[rr],a[rt]);
        lazy[rr]=1;
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(L>R)
        return;
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        a[rt]=max(a[rt],val);
        lazy[rt]=1;;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}


ll query(int rt,int l,int r,int L,int R)
{
    if(L==0&&R==0)
        return 0ll;
    if(r<L||l>R)
        return -2e18;
    if(r<=R&&l>=L)
    {
        return a[rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    return max(query(lr,l,mid,L,R),query(rr,mid+1,r,L,R));
}



int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    
    int L=0;
    for(int i=1;i<=n;i++)
    {
        while(L>0&&h[st[L]]>h[i])
        {
            L--;
        }
        pre[i]=st[L];
        st[++L]=i;
    }
    
    build(1,1,n);
    
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp[i]=b[i];
            upd(1,1,n,1,1,dp[i]);
            continue;
        }
        if(pre[i]==0)
        {
            dp[i]=max(query(1,1,n,1,i-1)+b[i],b[i]);
        }
        else
            dp[i]=max(query(1,1,n,pre[i],i-1)+b[i],query(1,1,n,pre[i],pre[i]));
        
        upd(1,1,n,i,i,dp[i]);
//        cout<<i<<' '<<pre[i]<<' '<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
    
    
    
    return 0;
}