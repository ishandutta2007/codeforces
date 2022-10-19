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
int a[500001],b[500001];
signed main()
{
	int n,ans,sum;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=(n+1)/2;i++)b[i]=a[2*i-1];
	for(int i=(n+1)/2+1;i<=n;i++)b[i]=a[2*i-n-1];
	for(int i=n+1;i<=2*n;i++)b[i]=b[i-n];
	ans=0;
	sum=0;
	for(int i=1;i<=(n+1)/2;i++)sum+=b[i];
	ans=sum;
	for(int i=(n+1)/2+1;i<=2*n;i++)
	{
		sum=sum+b[i]-b[i-(n+1)/2];
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}