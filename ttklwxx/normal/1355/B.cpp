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
int a[400001];
signed main()
{
	int t,n,x,ans=0,sy=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			x=read();
			a[x]++;
		}
		ans=0;
		sy=0;
		for(int i=1;i<=n;i++)
		{
			ans+=(a[i]+sy)/i;
			sy=(a[i]+sy)%i;
			a[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}