#include<iostream>
#include<cstdio>
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
int a[200005];
signed main()
{
	int t,n,x,y,maxn,minn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		maxn=0;
		minn=1000000000;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			maxn=max(maxn,a[i]);
			minn=min(minn,a[i]);
		}
		x=a[1];
		for(int i=1;i<=n;i++)
		{
			if(i>1&&a[i]>a[i-1])x+=a[i]-a[i-1];
		}
		if(x==maxn)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}