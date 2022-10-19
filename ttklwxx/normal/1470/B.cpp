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
int a[2000005],sl[2000005],sz[2000005];
signed main()
{
	int t,n,ans1,ans2,q,x;
	t=read();
	for(int i=1;i<=1000000;i++)
	{
		if(sz[i]!=0)continue;
		sz[i]=i;
		for(int j=1;j*j*i<=1000000;j++)sz[i*j*j]=i;
	}
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sl[sz[a[i]]]++;
		}
		ans1=0;
		for(int i=1;i<=n;i++)ans1=max(ans1,sl[sz[a[i]]]);
		ans2=0;
		for(int i=1;i<=n;i++)if(sz[a[i]]==1||sl[sz[a[i]]]%2==0)
		{
			ans2+=sl[sz[a[i]]];
			sl[sz[a[i]]]=0;
		}
		q=read();
		for(int i=1;i<=q;i++)
		{
			x=read();
			if(x==0)printf("%lld\n",ans1);
			else printf("%lld\n",max(ans1,ans2));
		}
		for(int i=1;i<=n;i++)sl[sz[a[i]]]=0;
	}
	return 0;
}