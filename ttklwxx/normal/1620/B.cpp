#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
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
char s[200005];
int k1,k2,k3,k4;
int x1[200005],x2[200005],y1[200005],y2[200005];
signed main()
{
	int t,n,x,w,h;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		w=read();
		h=read();
		k1=read();
		for(int i=1;i<=k1;i++)x1[i]=read();
		k2=read();
		for(int i=1;i<=k2;i++)x2[i]=read();
		k3=read();
		for(int i=1;i<=k3;i++)y1[i]=read();
		k4=read();
		for(int i=1;i<=k4;i++)y2[i]=read();
		printf("%lld\n",max(max((x1[k1]-x1[1])*h,(x2[k2]-x2[1])*h),max((y1[k3]-y1[1])*w,(y2[k4]-y2[1])*w)));
	}
	return 0;
}