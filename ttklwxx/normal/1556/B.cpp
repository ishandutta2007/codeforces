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
int a[100005];
int wz[100005],cnt;
inline int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t,n,sl,ans,nans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		sl=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]%2==0)sl++;
		}
		if(n%2==0)
		{
			if(sl!=n/2)
			{
				printf("-1\n");
				continue;
			}
			ans=0;
			cnt=0;
			for(int i=1;i<=n;i++)if(a[i]%2==0)wz[++cnt]=i; 
			for(int i=1;i<=n/2;i++)ans+=jdz(wz[i]-(i*2-1));
			nans=0;
			for(int i=1;i<=n/2;i++)nans+=jdz(wz[i]-(i*2));
			printf("%lld\n",min(ans,nans));
			continue;
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0)wz[++cnt]=i;
		}
		if(sl==n/2)
		{
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=jdz(wz[i]-(i*2));
			printf("%lld\n",ans);
			continue;
		}
		else if(sl==n/2+1)
		{
			ans=0;
			for(int i=1;i<=n/2+1;i++)ans+=jdz(wz[i]-(i*2-1));
			printf("%lld\n",ans);
			continue;
		}
		printf("-1\n");
		
	}
	return 0;
}