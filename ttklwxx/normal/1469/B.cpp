#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[205],b[205];
int main()
{
	int t,n,m,x,y,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=y=0;
		for(int i=1;i<=n;i++)a[i]=read()+a[i-1],x=max(x,a[i]);
		m=read();
		for(int i=1;i<=m;i++)b[i]=read()+b[i-1],y=max(y,b[i]);
		printf("%d\n",x+y);
	}
	return 0;
}