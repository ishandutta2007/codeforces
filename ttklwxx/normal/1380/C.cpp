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
int a[200001];
bool bi(int x,int y)
{
	return x>y;
}
int main()
{
	int t,n,x,ans,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		sl=0;
		sort(a+1,a+n+1,bi);
		for(int i=1;i<=n;i++)
		{
			sl++;
			if(1LL*sl*a[i]>=1LL*x)
			{
				sl=0;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}