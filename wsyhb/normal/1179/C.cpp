#include<bits/stdc++.h>
using namespace std;
int range;
const int max_range=1e6+5;
int v[max_range],val[max_range<<2],lazy[max_range<<2];
void build(int p,int l,int r)
{
    if(l==r)
    {
        val[p]=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    val[p]=max(val[p<<1],val[p<<1|1]);
}
inline void push_down(int p)
{
    val[p<<1]+=lazy[p];
    val[p<<1|1]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    lazy[p]=0;
}
void modify(int p,int l,int r,int a,int b,int v)
{
    if(a<=l&&r<=b)
    {
        val[p]+=v;
        lazy[p]+=v;
        return;
    }
    if(lazy[p])
        push_down(p);
    int mid=(l+r)>>1;
    if(a<=mid)
        modify(p<<1,l,mid,a,b,v);
    if(b>mid)
        modify(p<<1|1,mid+1,r,a,b,v);
    val[p]=max(val[p<<1],val[p<<1|1]);
}
int res;
void query(int p,int l,int r)
{
    if(l==r)
    {
        res=l;
        return;
    }
    if(lazy[p])
        push_down(p);
    int mid=(l+r)>>1;
    if(val[p<<1|1]>0)
        query(p<<1|1,mid+1,r);
    else
        query(p<<1,l,mid);
}
const int max_n=3e5+5;
const int max_m=3e5+5;
const int max_q=3e5+5;
int a[max_n],b[max_m],op[max_q],i[max_q],x[max_q];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        ++v[a[i]];
        range=max(range,a[i]);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d",b+i);
        --v[b[i]];
        range=max(range,b[i]);
    }
    for(int i=range;i>=1;--i)
        v[i]+=v[i+1];
    int q;
    scanf("%d",&q);
    for(int k=1;k<=q;++k)
    {
        scanf("%d%d%d",op+k,i+k,x+k);
        range=max(range,x[k]);
    }
    build(1,1,range);
    for(int k=1;k<=q;++k)
    {
        if(op[k]==1)
        {
            modify(1,1,range,1,a[i[k]],-1);
            modify(1,1,range,1,a[i[k]]=x[k],1);
        }
        else
        {
            modify(1,1,range,1,b[i[k]],1);
            modify(1,1,range,1,b[i[k]]=x[k],-1);
        }
        if(val[1]>0)
            query(1,1,range);
        else
            res=-1;
        printf("%d\n",res);
    }
    return 0;
}