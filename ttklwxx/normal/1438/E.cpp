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
int a[1000005];
signed main()
{
	int n,het=0,ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		het=0;
		for(int j=i+1;j<=n;j++)
		{
			if(het>a[i]*2)break;
			if(a[j]>a[i])
			{
				het+=a[j];
				continue;
			}
			if(j!=i+1&&(a[i]^a[j])==het)ans++;
			het+=a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		het=0;
		for(int j=i-1;j>=1;j--)
		{
			if(het>a[i]*2)break;
			if(a[j]>a[i])
			{
				het+=a[j];
				continue;
			}
			if(j!=i-1&&(a[i]^a[j])==het)ans++;
			het+=a[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}