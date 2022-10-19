#include<iostream>
#include<cstdio>
#include<cmath>
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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int a[50005];
signed main()
{
	int n,sth,ans=1000000000000000000LL,now;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n+1;i++)
	{
		sth=0;
		now=0;
		for(int j=i-1;j>=1;j--)
		{
			sth=(sth)/a[j]*a[j]+a[j];
			now+=sth/a[j];
		}
		sth=-1;
		for(int j=i;j<=n;j++)
		{
			if(sth==-1)sth=0;
			else sth=(sth)/a[j]*a[j]+a[j];
			now+=sth/a[j];
		}
		//printf("%lld %lld\n",i,now);
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}