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
int a[200005];
signed main()
{
	int t,n,m,minn,mpos,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		minn=2147483647;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<minn)
			{
				minn=a[i];
				mpos=i;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==mpos%2)continue;
			ans++;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
		{
			if(i%2==mpos%2)continue;
			printf("%lld %lld %lld %lld\n",mpos,i,minn,1000000007LL);
		}
	}
	return 0;
}