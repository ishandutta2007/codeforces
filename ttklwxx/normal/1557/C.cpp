#include<iostream>
#include<cstdio>
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
int jc[200005],njc[200005];
int main()
{
	jc[0]=1;
	for(int i=1;i<=200000;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[200000]=ksm(jc[200000],mod-2);
	for(int i=199999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	int t,n,k,ans,tans,cf;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(n%2==1)
		{
			ans=0;
			for(int i=0;i<n;i+=2)
			{
				ans=(ans+1LL*jc[n]*njc[i]%mod*njc[n-i]%mod)%mod;
			}
			ans=(ans+1)%mod;
			printf("%d\n",ksm(ans,k)); 
		}
		else
		{
			ans=0;
			for(int i=0;i<n;i+=2)
			{
				ans=(ans+1LL*jc[n]*njc[i]%mod*njc[n-i]%mod)%mod;
			}
			tans=0;
			for(int i=1;i<=k;i++)
			{
				tans=(tans+1LL*ksm(ans,k-i)*ksm(2,1LL*n*(i-1)%(mod-1)))%mod;
			}
			tans=(tans+ksm(ans,k))%mod;
			printf("%d\n",tans);
		}
	}
	return 0;
}