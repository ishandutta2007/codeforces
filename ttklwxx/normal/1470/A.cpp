#include<iostream>
#include<cstdio>
#include<algorithm>
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
int k[300005],c[300005];
signed main()
{
	int t,n,m,minn,ans=0;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)k[i]=read();
		for(int i=1;i<=m;i++)c[i]=read();
		sort(k+1,k+n+1);
		minn=1;
		ans=0;
		for(int i=n;i>=1;i--)
		{
			if(minn<k[i])
			{
			ans+=c[minn];
			minn++;
			}
			else ans+=c[k[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}