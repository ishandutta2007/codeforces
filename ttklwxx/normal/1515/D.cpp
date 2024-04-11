#include<iostream>
#include<cstdio>
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
int cxl[200005],cxr[200005],a[200005];
bool vis[200005];
int main()
{
	int t,n,l,r,x,tans,ans2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		l=read();
		r=read();
		for(int i=1;i<=l;i++)
		{
			a[i]=read();
			if(l>r)cxl[a[i]]++;
			else cxr[a[i]]++;
		}
		for(int i=l+1;i<=n;i++)
		{
			a[i]=read();
			if(l>r)cxr[a[i]]++;
			else cxl[a[i]]++;
		}
		if(l<=r)swap(l,r);
		tans=n;
		for(int i=1;i<=n;i++)
		{
			x=min(cxl[i],cxr[i]);
			tans-=x*2;
			cxl[i]-=x;
			cxr[i]-=x;
		}
		ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(cxl[i]>0)ans2+=cxl[i]/2;
		}
		printf("%d\n",(l-r)/2+tans/2-min(ans2,(l-r)/2));
		for(int i=1;i<=n;i++)
		{
			cxl[i]=0;
			cxr[i]=0;
		}
	}
	return 0;
}