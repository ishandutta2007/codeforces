#include<iostream>
#include<cstdio>
#define tm 998244353
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
int dp[18][2000005];
int a[10000005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%tm;
		n=1LL*n*n%tm;
		k>>=1; 
	}
	return ans;
}
int main()
{
	int n,x,y,k,mod;
	int lc=16*9*11*13*7*5;
	int ans=0;
	n=read();
	a[1]=read();
	x=read();
	y=read();
	k=read();
	mod=read();
	for(int i=2;i<=n;i++)
	{
		a[i]=(1LL*a[i-1]*x+y)%mod;
	//	printf("%d\n",a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+1LL*k*ksm(n,k-1)%tm*(a[i]/lc)%tm*lc%tm)%tm;
		a[i]%=lc;
		dp[0][a[i]]++;
	}
	for(int i=0;i<=k-1;i++)
	{
		for(int j=0;j<lc;j++)
		{
			dp[i+1][j]=(dp[i+1][j]+1LL*dp[i][j]*(n-1)%tm)%tm;
			dp[i+1][j-j%(i+1)]=(dp[i+1][j-j%(i+1)]+dp[i][j])%tm;
		}
	}
	for(int i=0;i<=k-1;i++)
	{
		for(int j=0;j<lc;j++)
		{
			ans=(ans+1LL*j*dp[i][j]%tm*ksm(n,k-i-1)%tm)%tm;
		}
	}
	printf("%d\n",ans); 
	return 0;
}