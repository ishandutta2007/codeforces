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
int a[200005];
int p[200005];
signed main()
{
	int t,n,l,r;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(a[n]==n)
		{
			for(int i=n-1;i>=1;i--)
			{
				printf("%d ",a[i]);
			}
			printf("%d",a[n]);
			printf("\n");
		}
		else if(a[1]==n)
		{
			for(int i=n;i>=2;i--)
			{
				printf("%d ",a[i]);
			}
			printf("%d",a[1]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}