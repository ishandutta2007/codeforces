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
	int t,n,ans1=0,ans2=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans1=0;
		ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1)ans1+=a[i];
			else ans2+=a[i];
		}
		if(ans1<=ans2)
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2==1)printf("1 ");
				else printf("%lld ",a[i]);
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i%2==0)printf("1 ");
				else printf("%lld ",a[i]);
			}
		}
		printf("\n");
	} 
	return 0;
}