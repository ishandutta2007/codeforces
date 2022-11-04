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
const int maxn=1000005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int N=maxn-2;

int sa[maxn],sb[maxn],a[maxn],b[maxn];
int lazy[maxn<<2],mx[maxn<<2];

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

int query(int rt,int l,int r)
{
    if(l==r)
        return l;
    if(mx[rt]<=0)
        return 0;
    pushdown(rt);
    int mid=(l+r)/2;
    if(mx[rr]>0)
        return query(rr,mid+1,r);
    return query(lr,l,mid);
}


int A[maxn],B[maxn];

int main()
{
    sync;
    int n,m;
    build(1,1,N);
    cin>>n>>m;
    int x;
    rep(i,1,n)
    {
        cin>>x;
        update(1,1,N,1,x,1);
        A[i]=x;
    }
    rep(i,1,m)
    {
        cin>>x;
        update(1,1,N,1,x,-1);
        B[i]=x;
    }
    
    int q;
    cin>>q;
    int k,id,val;
    while(q--)
    {
        cin>>k>>id>>val;
        if(k==1)
        {
            update(1,1,N,1,A[id],-1);
            A[id]=val;
            update(1,1,N,1,A[id],1);
            int ans=query(1,1,N);
            if(ans==0)
                cout<<-1<<endl;
            else
                cout<<ans<<endl;
        }
        else
        {
            update(1,1,N,1,B[id],1);
            B[id]=val;
            update(1,1,N,1,B[id],-1);
            int ans=query(1,1,N);
            if(ans==0)
                cout<<-1<<endl;
            else
                cout<<ans<<endl;
        }
    }
    return 0;
}