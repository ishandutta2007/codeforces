#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=400005;
const ll Mod=1e9+7;

int a[maxn<<2],sum;

void pushup(int rt)   //
{
    a[rt]=min(a[lr],a[rr]);
}
//void build(int rt,int l,int r)// 1n
//{
//    if(l==r)
//    {
//        a[rt]=0;
//        return ;
//    }
//    int mid=(l+r)/2;
//    build(lr,l,mid);
//    build(rr,mid+1,r);
//    pushup(rt);
//}
int query(int rt,int l,int r)//LRL,R
{
    if(l==r)
    {
        sum=l-1;
        return a[rt];
    }
    int mid=(l+r)/2;
    if(a[lr]<=a[rr])
        return query(lr,l,mid);
    return query(rr,mid+1,r);
}
void update(int rt,int l,int r,int pos)//,,lazy pushdown
{
    if(l==r)
    {
        a[rt]++;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(lr,l,mid,pos);
    else
        update(rr,mid+1,r,pos);
    pushup(rt); //
    return;
}

int main()
{
    sync;
    int q,x,y,p=0;
    cin>>q>>x;
//    build(1,1,x);
    while(q--)
    {
        cin>>y;
        update(1,1,x,(y%x)+1);
        sum=0;
        p=query(1,1,x);
        cout<<p*x+sum<<endl;
    }
    return 0;
}