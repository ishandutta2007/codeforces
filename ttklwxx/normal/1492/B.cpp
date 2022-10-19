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
int a[200005],maxn[2000005];
signed main()
{
	int t,n,pos,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			maxn[i]=max(maxn[i-1],a[i]);
		}
		sth=n;
		for(int i=n;i>=1;i--)
		{
			if(maxn[i]==a[i])
			{
				for(int j=i;j<=sth;j++)printf("%lld ",a[j]);
				sth=i-1;
			} 
		}
		printf("\n");
	}
	return 0;
}