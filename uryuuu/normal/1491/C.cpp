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
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
const ll Mod=1000000007;
//const ll Mod=998244353;

#define int ll

int s[maxn];
int lv;

struct node
{
    int l,r,lazy,len,sum;
}a[maxn<<2];

void pushup(int rt)
{
    a[rt].sum=a[lr].sum+a[rr].sum;
}
void build(int rt,int l,int r)//1,n,
{
    a[rt].l=l;
    a[rt].r=r;
    a[rt].len=r-l+1;
    a[rt].lazy=0;
    if(l==r)
    {
        a[rt].sum=0ll;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}
void pushdown(int rt)//
{
    if(a[rt].lazy)
    {
        a[lr].sum+=a[rt].lazy*a[lr].len;
        a[lr].lazy+=a[rt].lazy;
        a[rr].sum+=a[rt].lazy*a[rr].len;
        a[rr].lazy+=a[rt].lazy;
        a[rt].lazy=0;
    }
}
void add(int rt,int L,int R,int s)//
{
    if(a[rt].l==L&&a[rt].r==R)
    {
        a[rt].sum+=a[rt].len*s;
        a[rt].lazy+=s;
        return;
    }
    pushdown(rt);//
    int mid=(a[rt].l+a[rt].r)/2;
    if(mid>=R)
        add(lr,L,R,s);
    else if(mid<L)//
        add(rr,L,R,s);
    else
    {
        add(lr,L,mid,s);
        add(rr,mid+1,R,s);
    }
    pushup(rt);
}

int query(int rt,int L,int R)//
{
    if(a[rt].l==L&&a[rt].r==R)
    {
        return a[rt].sum;
    }
    pushdown(rt);
    int mid=(a[rt].l+a[rt].r)/2;
    if(mid>=R)
        return query(lr,L,R);
    else if(mid<L)
        return query(rr,L,R);
    return query(lr,L,mid)+query(rr,mid+1,R);
}


signed main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0ll;
        int d;
        int L,R;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            d=query(1,i,i);
            lv=max(0ll,s[i]-1ll-d);
//            cout<<d<<' '<<lv<<' '<<s[i]<<endl;
            sum+=1ll*lv;
            if(s[i]>1&&i+2<=n)
            {
                R=min(n,i+s[i]);
                L=i+2;
                add(1,L,R,1ll);
            }
            if(d>s[i]-1&&i<n)
            {
                add(1,i+1,i+1,d-(s[i]-1));
            }
        }
        cout<<sum<<endl;
        
    }
    
    return 0;
}