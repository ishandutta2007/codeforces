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
int a[100001];
int main()
{
	int t,n,x,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i+1]>2*a[i])
			{
				x=a[i]*2;
				while(x<a[i+1])
				{
					x*=2;
					ans++;
				}
			}
			if(a[i]>2*a[i+1])
			{
				x=a[i+1]*2;
				while(x<a[i])
				{
					x*=2;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}