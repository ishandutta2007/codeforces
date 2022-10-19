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
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,n,ans=0,os=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		os=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]%2==0)os++;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==0)continue;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]%2==0)continue;
				if(gcd(a[i],a[j])!=1)ans++;
			}
		}
		printf("%lld\n",os*(os-1)/2+os*(n-os)+ans);
	} 
	return 0;
}