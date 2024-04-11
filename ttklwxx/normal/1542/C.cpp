#include<iostream>
#include<cstdio>
#define int long long
#define mod 1000000007
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
long long lc;
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,n,ans=0,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=1;
		ans=0;
		lc=1;
		for(int i=1;i<=60;i++)
		{
			if(n<lc)break;
			ans=(ans+(n/lc))%mod;
			lc=lc/gcd(lc,i+1)*(i+1);
		}
		printf("%lld\n",(ans+n)%mod);
	} 
	return 0;
}