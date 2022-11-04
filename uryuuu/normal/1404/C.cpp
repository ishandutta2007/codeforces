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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn<<2];
int lazy[maxn<<2];
int b[maxn];

void pushup(int rt)
{
    a[rt]=min(a[lr],a[rr]);
}

void build(int rt,int l,int r)//1,n,
{
    a[rt]=99999999;
    lazy[rt]=0;
    if(l==r)
    {
        a[rt]=99999999;
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
        a[lr]+=lazy[rt];
        lazy[lr]+=lazy[rt];
        a[rr]+=lazy[rt];
        lazy[rr]+=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,int val)
{
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        a[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}

void upd1(int rt,int l,int r,int pos,int val)
{
    if(l==r)
    {
        a[rt]=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid>=pos)
        upd1(lr,l,mid,pos,val);
    else
        upd1(rr,mid+1,r,pos,val);
    pushup(rt);
}


int pos;
int mn;

void query(int rt,int l,int r)
{
    if(l==r)
    {
        pos=l;
        mn=a[rt];
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(a[lr]<a[rr])
        query(lr,l,mid);
    else
        query(rr,mid+1,r);
}

int ans[maxn];
vector<int>g[maxn];
struct node
{
    int L,R;
}Q[maxn];


int pre[maxn];

void add(int x)
{
    while(x<=maxn-2)
    {
        pre[x]++;
        x+=lb(x);
    }
}

int qry(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=pre[x];
        x-=lb(x);
    }
    return ans;
}



int main()
{
    sync;
    int n,q;
    cin>>n>>q;
    rep(i,1,n)
    cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        b[i]=i-b[i];
        if(b[i]<0)
        {
            b[i]=99999999;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>Q[i].L>>Q[i].R;
        g[Q[i].L].push_back(i);
    }
    
//    cout<<"FUCK"<<endl;
//    int sum=0;
    build(1,1,n);
    
   
    for(int i=n;i>=1;i--)
    {
        upd1(1,1,n,i,b[i]);
        while(1)
        {
            mn=9999999;
            query(1,1,n);
//            cout<<pos<<' '<<mn<<endl;
            if(mn<=0)
            {
                add(pos);
                upd(1,1,n,pos,n,-1);
                upd1(1,1,n,pos,9999999);
            }
            else
                break;
        }
        for(int id:g[i-1])
        {
            int R=Q[id].R;
            ans[id]=qry(n-R);
        }
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}