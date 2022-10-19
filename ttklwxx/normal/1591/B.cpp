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
int a[200005];
int main()
{
	int t,n,ans,las;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		las=a[n];
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]>las)las=a[i],ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}