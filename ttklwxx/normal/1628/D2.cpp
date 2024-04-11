#include<iostream>
#include<cstdio>
#include<cstring>
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
int jc[1000005],njc[1000005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
int c(int n,int m)
{
	if(m>n)return 0;
	return 1LL*jc[n]*njc[m]%mod*njc[n-m]%mod;
}
signed main()
{
	int t,n,m,k,ans=0;
	jc[0]=1;
	for(int i=1;i<=1000000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[1000000]=ksm(jc[1000000],mod-2);
	for(int i=999999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		ans=0;
		for(int i=1;i<=m;i++)ans=(ans+1LL*(2*i-1)*c(n-1,m-i)%mod)%mod;
		//printf("%lld\n",ans);
		ans=1LL*ans*ksm((mod+1)/2,n-1)%mod;
		printf("%lld\n",1LL*ans*k%mod);
	}
	return 0;
}