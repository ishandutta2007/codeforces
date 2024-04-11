#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define p 1000000007
struct N
{
	int l,r,sa;
	ll a[6];
}t[400000];
int a[100020];
ll S[100020][6];
ll C[21][21];
int qqq;
void add(const N&a,const N&b,N&c)
{
	if(a.l+a.r==0)
	{
		c=b;
		return;
	}
	if(b.l+b.r==0)
	{
		c=a;
		return;
	}
	c.l=a.l,c.r=b.r;
	static long long w[6];
	static long long r[6];
	int len=a.r-a.l+1;
	for(int i=0;i<6;i++)
		w[i]=a.a[i];
	for(int i=r[0]=1;i<6;i++)
		r[i]=r[i-1]*len%p;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<=i;j++)
			w[i]+=C[i][j]*r[i-j]%p*b.a[j];
	}
	for(int i=0;i<6;i++)
		c.a[i]=w[i]%p;
}

void sam(int x,int z)
{
	t[x].sa=z;
	int len=t[x].r-t[x].l+1;
	for(int i=0;i<6;i++)
		t[x].a[i]=S[len][i]%p*z%p;;
	return;
}
void pd(int x)
{
	if(t[x].l==t[x].r)
		return;
	if(t[x].sa!=-1)
	{
		sam(2*x,t[x].sa);
		sam(2*x+1,t[x].sa);
		t[x].sa=-1;
	}
}
void sam(int x,int l,int r,int z)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		sam(x,z);
		return;
	}
	else if(t[x].r<l||t[x].l>r)
		return;
	pd(x);
	sam(x*2,l,r,z);
	sam(x*2+1,l,r,z);
	add(t[x*2],t[x*2+1],t[x]);
}
void bd(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	t[x].sa=-1;
	if(l==r)
	{
		for(int i=0;i<6;i++)
			t[x].a[i]=a[l];
		return;
	}
	int m=l+r>>1;
	int L=x*2,R=L+1;
	bd(L,l,m);
	bd(R,m+1,r);
	add(t[L],t[R],t[x]);
}
void ask(N& z,int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		z.l=t[x].l;
		z.r=t[x].r;
		for(int i=0;i<6;i++)
			z.a[i]=t[x].a[i];
		return;
	}
	else if(t[x].r<l||t[x].l>r)
	{
		z.r=z.l=0;
		for(int i=0;i<6;i++)
			z.a[i]=0;
		return;
	}
	N zl,zr;
	pd(x);
	int L=x*2,R=L+1;
	ask(zl,L,l,r);
	ask(zr,R,l,r);
	add(zl,zr,z);
	return;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]%=p;
		if(a[i]<0)
			a[i]+=p;
	}
	for(int i=0;i<20;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	for(int i=1;i<=n;i++)
		S[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
			S[i][j+1]=S[i][j]*i%p;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=5;j++)
			S[i][j]=(S[i-1][j]+S[i][j])%p;
	bd(1,1,n);
	for(int i=0;i<q;i++)
	{
		char o[5];
		int x,y,z;
		scanf("%s %d %d %d",&o,&x,&y,&z);
		if(*o=='=')
			sam(1,x,y,z);
		else if(*o=='?')
		{
			qqq=z;
			N ans;
			ask(ans,1,x,y);
			printf("%d\n",ans.a[qqq]);
		}
	}
	return 0;
}