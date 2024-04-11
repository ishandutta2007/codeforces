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
int c(int n,int m)
{
	if(n<m)return 0;
	int ans=1;
	if(m>n-m)return c(n,n-m);
	for(int i=1;i<=m;i++)ans=1LL*ans*(n+1-i)%mod*1LL*ksm(i,mod-2)%mod;
	return ans;
}
int main()
{
	int n,k,ans=0,r;
	n=read();
	k=read();
	for(int l=1;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans=(ans+1LL*(r-l+1)*c(n/l-1,k-1)%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}