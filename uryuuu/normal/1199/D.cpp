#include<iostream>
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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
const ll Mod=1e9+7;
using namespace std;
#define maxn 200005
int n,m;
struct node
{
    int zx,lazy;
}t[maxn<<2];
void pushdown(int rt)
{
    t[lr].lazy=max(t[rt].lazy,t[lr].lazy);
    t[rr].lazy=max(t[rt].lazy,t[rr].lazy);
    t[rt].lazy=0;
}
void build(int rt,int l,int r)
{
    if(l==r)
    {
        cin>>t[rt].zx;
        t[rt].lazy=0;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
}
void changex(int rt,int l,int r,int pos,int x)
{
    if(l==r)
    {
        t[rt].zx=x;
        t[rt].lazy=0;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(pos<=mid)
        changex(lr,l,mid,pos,x);
    else
        changex(rr,mid+1,r,pos,x);
}
void query(int rt,int l,int r)
{
    if(l==r)
    {
        cout<<max(t[rt].lazy,t[rt].zx)<<' ';
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    query(lr,l,mid);
    query(rr,mid+1,r);
}
int main()
{
    sync;
    cin>>n;
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int op,p,xx;
        cin>>op;
        if(op==2)
        {
            cin>>xx;
            t[1].lazy=max(t[1].lazy,xx);
        }
        else
        {
            cin>>p>>xx;
            changex(1,1,n,p,xx);
        }
    }
    query(1,1,n);
    cout<<endl;
    return 0;
}