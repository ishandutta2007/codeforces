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
const int maxn=600010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;
int n,k;
int b[maxn];
int a[maxn<<2],lazy[maxn<<2];

void pushup(int rt)
{
    a[rt]=a[lr]+a[rr];
}

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
    pushup(rt);
}

void pushdown(int rt,int l,int r)//
{
    if(lazy[rt])
    {
        int mid=(l+r)/2;
        a[lr]+=lazy[rt]*(mid-l+1);
        lazy[lr]+=lazy[rt];
        a[rr]+=lazy[rt]*(r-mid);
        lazy[rr]+=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        a[rt]+=val*(r-l+1);
        lazy[rt]+=val;
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}


int query(int rt,int l,int r,int L,int R)
{
    if(r<L||l>R)
        return 0;
    if(r<=R&&l>=L)
    {
        return a[rt];
    }
    pushdown(rt,l,r);
    int mid=(l+r)/2;
    return query(lr,l,mid,L,R)+query(rr,mid+1,r,L,R);
}

int findfst(int rt,int l,int r)
{
    if(l==r)
        return l;
    int mid=(l+r)/2;
    pushdown(rt,l,r);
    if(a[lr])
        return findfst(lr,l,mid);
    else
        return findfst(rr,mid+1,r);
}

bool cmp(int a,int b)
{
    return a>b;
}

int check(int dep)
{
    int N=600000;
    build(1,1,N);
    upd(1,1,N,2,1+(b[1]-1)/2,1);
    upd(1,1,N,2,1+b[1]-1-(b[1]-1)/2,1);
//    cout<<query(1,1,N,1,dep)<<endl;
    if(query(1,1,N,1,dep)>=k)
        return 1;
    int d;
    for(int i=2;i<=n;i++)
    {
        if(b[i]<=2)
            return 0;
        d=findfst(1,1,N);
        upd(1,1,N,d,d,-1);
        upd(1,1,N,d+2,min(d+1+(b[i]-1)/2,N),2);
        if(b[i]%2==0&&d+1+b[i]-1-(b[i]-1)/2<=N)
            upd(1,1,N,d+1+b[i]-1-(b[i]-1)/2,d+1+b[i]-1-(b[i]-1)/2,1);
        if(query(1,1,N,1,dep)>=k)
            return 1;
    }
    return 0;
}

int main()
{
    sync;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(b+1,b+n+1,cmp);
    if(b[1]==2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int l=1,r=600000,mid,ans=99999999;
    while(l<r)
    {
        mid=(l+r)/2;
//        cout<<mid<<' ';
        if(check(mid))
        {
            ans=min(ans,mid);
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(ans==99999999)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    
    return 0;
}