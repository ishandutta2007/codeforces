#include<iostream>
#include<cstdio>
#include<cmath>
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
int cf[200001];
signed main()
{
	int n;
	n=read();
	if(n==1)
	{
		printf("10\n");
		return 0;
	}
	cf[0]=1;
	for(int i=1;i<=n;i++)cf[i]=1LL*cf[i-1]*10%mod;
	for(int i=1;i<=n-1;i++)
	{
		printf("%d ",(180LL*cf[n-i-1]%mod+810LL*(n-i-1)%mod*cf[n-i-2]%mod)%mod);
	}
	printf("10\n");
	return 0;
}