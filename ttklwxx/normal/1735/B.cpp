#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[1005];
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<2*a[1])continue;
			ans+=(a[i]-1)/(2*a[1]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}