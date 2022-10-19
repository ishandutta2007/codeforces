#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct query
{
	int l,r;
}a[800004];
bool bi(struct query x,struct query y)
{
	return x.r<y.r;
}
bool bibi(struct query x,struct query y)
{
	return x.l>y.l;
}
int main()
{
	int t,n,m,x,ansl,ansr;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		m=read();
		for(int i=1;i<=m;i++)
		{
			a[i].l=read();
			a[i].r=read();
		}
		ansr=x;
		for(int i=1;i<=m;i++)
		{
			if(a[i].r>ansr&&a[i].l<=ansr)ansr=a[i].r;
		}
		ansl=x;
		for(int i=1;i<=m;i++)
		{
			if(a[i].l<ansl&&a[i].r>=ansl)ansl=a[i].l;
		}
		printf("%d\n",ansr-ansl+1);
	}
	return 0;
}