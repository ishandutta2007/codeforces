#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 998244353
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
int a[200005],jc[200005],ny[200005];
int main()
{
	int t,n,sl;
	bool flag,fl;
	jc[0]=1;
	for(int i=1;i<=200000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	ny[1]=1;
	for(int i=2;i<=200000;i++)ny[i]=1LL*(mod-mod/i)*ny[mod%i]%mod;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		if(a[n]-a[n-1]>=2)
		{
			printf("0\n");
			continue;
		}
		if(a[n]-a[n-1]==0)
		{
			printf("%d\n",jc[n]);
			continue;
		}
		sl=0;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]!=a[n]-1)break;
			sl++;
		}
		printf("%d\n",1LL*jc[n]*sl%mod*ny[sl+1]%mod);
	}
	return 0;
}