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
int a[100005];
signed main()
{
	int t,n,k=0,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		ans=0; 
		for(int i=1;i<=k;i++)ans+=a[n-i-k+1]/a[n-i+1];
		for(int i=1;i<=n-2*k;i++)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}