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
#define lr (rt<<1)
#define rr (rt<<1|1)
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
const int maxn =1000010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
const ll mod=1004535809;

ll a[maxn<<2];
int lazy[20];


void build(int rt,int l,int r)
{
    if(l==r)
    {
        cin>>a[rt];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    a[rt]=a[lr]+a[rr];
}

void upd(int rt,int l,int r,int pos,int val,int dep)
{
    if(l==r)
    {
        a[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        upd(lr|lazy[dep],l,mid,pos,val,dep-1);
    else
        upd(rr^lazy[dep],mid+1,r,pos,val,dep-1);
    a[rt]=a[lr]+a[rr];
}

ll query(int rt,int l,int r,int L,int R,int dep)
{
    if(l>=L&&r<=R)
    {
        return a[rt];
    }
    int mid=(l+r)/2;
    if(R<=mid)
        return query(lr|lazy[dep],l,mid,L,R,dep-1);
    else if(L>mid)
        return query(rr^lazy[dep],mid+1,r,L,R,dep-1);
    return query(lr|lazy[dep],l,mid,L,R,dep-1)+query(rr^lazy[dep],mid+1,r,L,R,dep-1);
}


int main()
{
    sync;
    int n,q;
    cin>>n>>q;
    int dep=n;
    n=1<<n;
    build(1,1,n);
    int op;
    int x,k;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x>>k;
            upd(1,1,n,x,k,dep);
        }
        else if(op==2)
        {
            cin>>k;
            for(int i=0;i<=k;i++)
                lazy[i]^=1;
        }
        else if(op==3)
        {
            cin>>k;
            lazy[k+1]^=1;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r,dep)<<endl;
        }
        
    }
    
    return 0;
}