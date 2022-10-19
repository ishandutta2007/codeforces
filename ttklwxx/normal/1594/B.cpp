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
signed main()
{
	int t,n,k,ans=0,cj=1;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		ans=0;
		cj=1;
		while(k!=0)
		{
			if(k&1)ans=(ans+cj)%mod;
			cj=cj*n%mod;
			k>>=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}