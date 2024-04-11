#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int MAX=100100;
int a[MAX],r[MAX],n;
bool cmp(int x,int y)
{return a[x]<a[y];}
void lisan()
{
    sort(r,r+n,cmp);
    int M=0;
    int pre=a[r[0]];
    a[r[0]]=++M;
    for(int i=1;i<n;i++)
    {
        if(a[r[i]]!=pre)
        {
            ++M;
            pre=a[r[i]];
        }
        a[r[i]]=M;
    }
}
int ans[MAX];
int va[MAX];
const int oo=1000000001;
struct Node
{
	int l,r,mi;
}p[4*MAX];
void init(int nu,int l,int r)
{
	p[nu].l=l;
	p[nu].r=r;
	p[nu].mi=r;
	if(l==r)return;
	int mid=(l+r)/2;
	init(nu*2,l,mid);
	init(nu*2+1,mid+1,r);
}
void update(int nu,int po,int x)
{
	if(p[nu].l==po&&p[nu].r==po)
	{
		return;
	}
	int mid=(p[nu].l+p[nu].r)/2;
	if(po<=mid)update(nu*2,po,x);
	else update(nu*2+1,po,x);
	if(va[p[nu*2].mi]<va[p[nu*2+1].mi])
	p[nu].mi=p[nu*2].mi;
	else p[nu].mi=p[nu*2+1].mi;
}
int read(int nu,int l,int r,int x)
{
//	if(x==a[0])printf("%d %d %d %d\n",nu,p[nu].mi,l,r);
	if(p[nu].l==p[nu].r)
	{
		if(va[p[nu].mi]<x)return p[nu].mi;
		return -1;
	}
	int mid=(p[nu].l+p[nu].r)/2;
	if(r<=mid)return read(nu*2,l,r,x);
	if(l>mid)return read(nu*2+1,l,r,x);
	else
	{
		if(va[p[nu*2+1].mi]<x)return read(nu*2+1,mid+1,r,x);
		else return read(nu*2,l,mid,x);
	}
}
int i;
int main()
{
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		//	r[i]=i;
		}
	//	lisan();
		init(1,0,n-1);
		for(i=0;i<n;i++)va[i]=oo;
		for(i=n-1;i>=0;i--)
		{
			int te=read(1,i,n-1,a[i]);
		//	printf("%d %d\n",i,te);
			if(te==-1)ans[i]=-1;
			else ans[i]=te-i-1;
			va[i]=a[i];
			update(1,i,a[i]);
		}
		for(i=0;i<n;i++)
		{
			printf("%d ",ans[i]);
		}
		puts("");
	}
}