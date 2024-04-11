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
int a[1001];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	if(n==2)
	{
		printf("%lld\n",a[1]|a[2]);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld\n",ans);
	return 0;
}