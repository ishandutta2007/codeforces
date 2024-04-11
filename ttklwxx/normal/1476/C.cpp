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
int c[200005],b[200005],a[200005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t,n,nans=0,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)c[i]=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		ans=0;
		nans=jdz(b[2]-a[2]);
		for(int i=2;i<=n-1;i++)
		{
			if(a[i+1]==b[i+1])
			{
				nans=nans+2+c[i]-1;
				ans=max(ans,nans);
				nans=0;
			}
			else
			{
				ans=max(ans,nans+2+c[i]-1);
				nans=nans+2+c[i]-1-jdz(b[i+1]-a[i+1]);
				nans=max(nans,jdz(b[i+1]-a[i+1]));
			}
		}
		ans=max(ans,nans+2+c[n]-1);
		printf("%lld\n",ans);
	}
	return 0;
}