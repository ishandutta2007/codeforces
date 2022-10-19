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
int h[200005];
int main()
{
	int t,n,k,maxh,minh;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)h[i]=read();
		maxh=h[1];
		minh=h[1];
		flag=false;
		for(int i=2;i<=n;i++)
		{
			minh=minh-k+1;
			maxh=maxh+k-1;
			maxh=min(maxh,h[i]+k-1);
			minh=max(minh,h[i]);
			if(minh>maxh)
			{
				flag=true;
				break;
			}
		}
		if(minh>h[n]||maxh<h[n]||flag==true)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}