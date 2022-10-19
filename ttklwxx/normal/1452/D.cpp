#include<iostream>
#include<cstdio>
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
int f[200005],jf[200005],of[200005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		n=1LL*n*n%mod;
		k>>=1;
	}
	return ans;
}
int main()
{
	int n;
	n=read();
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)f[i]=(of[i-1]+1)%mod;
		else f[i]=jf[i-1];
		if(i==1)
		{
			jf[i]=f[i];
			continue;
		}
		if(i%2==1)jf[i]=(jf[i-2]+f[i])%mod;
		else of[i]=(of[i-2]+f[i])%mod;
	}
	printf("%d\n",1LL*f[n]*ksm((mod+1)/2,n)%mod);
	return 0;
}