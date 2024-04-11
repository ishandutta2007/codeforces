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
int cx[200005];
int main()
{
	int t,n,ans=0,nans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			nans=0;
			for(int j=i;j<=n;j++)
			{
				if(a[j]==0)nans+=2;
				else nans++;
				ans+=nans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}