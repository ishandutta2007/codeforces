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
int a[200005];
signed main()
{
	int t,n,k,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		s=0;
		for(int i=n;i>=n-k;i--)s+=a[i];
		if(k==0)printf("%lld\n",a[n]-a[1]);
		else printf("%lld\n",s);
	}
	return 0;
}