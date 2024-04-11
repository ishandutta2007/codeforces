#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int MAX=100100;
struct Node
{
    int l,r,ma;
}p[4*MAX];
LL ti[MAX];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    p[nu].ma=l;
    if(l==r)return;
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
}
void update(int nu,int po,int x)
{
    if(p[nu].l==po&&p[nu].r==po)
    {p[nu].ma=x;return;}
    int mid=(p[nu].l+p[nu].r)/2;
    if(po<=mid)update(nu*2,po,x);
    else update(nu*2+1,po,x);
    if(ti[p[nu*2].ma]<ti[p[nu*2+1].ma])
    p[nu].ma=p[nu*2].ma;
    else p[nu].ma=p[nu*2+1].ma;
}
int read(int nu,int l,int r)
{
    if(p[nu].l==l&&p[nu].r==r)
    return p[nu].ma;
    int mid=(p[nu].l+p[nu].r)/2;
    if(r<=mid)return read(nu*2,l,r);
    if(l>mid)return read(nu*2+1,l,r);
    int a=read(nu*2,l,mid);
    int b=read(nu*2+1,mid+1,r);
    if(ti[a]<ti[b])return a;return b;
}
LL tmp[MAX],in[MAX];
int nu[10];
LL ct[10];
int _,n,m,i,x,y;
int main()
{
    while(~scanf("%d",&nu[1]))
    {
        scanf("%d%d",&nu[2],&nu[3]);
        for(i=1;i<=3;i++)scanf("%I64d",&ct[i]);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&in[i]);
        }
        m=min(n,nu[1]);
        memset(ti,0,sizeof(ti));
        init(1,1,m);
        LL TT=0;
        for(i=0;i<n;i++)
        {
            int te=read(1,1,m);
            TT=max(in[i],TT);
            tmp[i]=max(TT,ti[te])+ct[1];
            ti[te]=tmp[i];
            update(1,te,te);
        }
    //  for(i=0;i<n;i++)printf("%d ",tmp[i]);puts("");
        m=min(n,nu[2]);
        memset(ti,0,sizeof(ti));
        init(1,1,m);
        TT=0;
        for(i=0;i<n;i++)
        {
            int te=read(1,1,m);
            TT=max(tmp[i],TT);
            tmp[i]=max(TT,ti[te])+ct[2];
            ti[te]=tmp[i];
            update(1,te,te);
        }
    //  for(i=0;i<n;i++)printf("%d ",tmp[i]);puts("");
        memset(ti,0,sizeof(ti));
        m=min(n,nu[3]);
        init(1,1,m);
        TT=0;
        for(i=0;i<n;i++)
        {
            int te=read(1,1,m);
            TT=max(tmp[i],TT);
            tmp[i]=max(TT,ti[te])+ct[3];
            ti[te]=tmp[i];
            update(1,te,te);
        }
    //  for(i=0;i<n;i++)printf("%d ",tmp[i]);puts("");
        LL ans=0;
        for(i=0;i<n;i++)
        {
            ans=max(ans,tmp[i]-in[i]);
        }
        cout<<ans<<endl;
    }
}