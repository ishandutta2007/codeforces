#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct N
{
	int c[20],w,l,r;
}t[262626],O;
int a[100020];
void ud(int *a,int *b,int *c)
{
	for(int i=0;i<20;i++)
		a[i]=b[i]+c[i];
}
void bd(int x,int l,int r)
{
	int m=l+r>>1;
	t[x].l=l;
	t[x].r=r;
	if(l==r)
	{
		for(int i=0;i<20;i++)
			t[x].c[i]=a[l]>>i&1;
		return;
	}
	bd(x*2,l,m);
	bd(x*2+1,m+1,r);
	ud(t[x].c,t[x*2].c,t[x*2+1].c);
}
void rev(int x,int w)
{
	t[x].w^=w;
	int len=t[x].r-t[x].l+1;
	for(int i=0;i<20;i++)
		if(w>>i&1)
			t[x].c[i]=len-t[x].c[i];
}
void pd(int x)
{
	if(t[x].l==t[x].r)
		return;
	if(t[x].w)
	{
		rev(x*2,t[x].w);
		rev(x*2+1,t[x].w);
		t[x].w=0;
	}
}
N qy(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x];
	if(r<t[x].l||t[x].r<l)
		return O;
	pd(x);
	N re;
	memset(re.c,0,sizeof re.c);
	ud(re.c,qy(x*2,l,r).c,qy(x*2+1,l,r).c);
	return re;
}
void cg(int x,int l,int r,int w)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		rev(x,w);
		return;
	}
	if(r<t[x].l||t[x].r<l)
		return;
	pd(x);
	cg(x*2,l,r,w);
	cg(x*2+1,l,r,w);
	ud(t[x].c,t[x*2].c,t[x*2+1].c);
}
int main()
{
	int n,m,o,l,r,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	bd(1,1,n);
	for(scanf("%d",&m);m--;)
	{
		scanf("%d %d %d",&o,&l,&r);
		if(o==1)
		{
			N c=qy(1,l,r);
			long long s=0;
			for(int i=0;i<20;i++)
				s+=(long long)c.c[i]<<i;
			printf("%I64d\n",s);
		}
		else
		{
			scanf("%d",&x);
			cg(1,l,r,x);
		}
	}
	return 0;
}