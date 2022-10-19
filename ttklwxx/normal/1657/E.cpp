#include<cstdio>
#include<cstring>
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
int n,m,c[255][255],dp[255][255];
int main()
{
	n=read();
	m=read();
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	dp[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<=j;k++)
			{
				dp[i][j]=(dp[i][j]+1ll*dp[i-1][j-k]*c[n-1-j+k][k]%mod*ksm(m-i+1,(j*2-k-1)*k/2)%mod)%mod;
			}
		}
	}
	printf("%d\n",dp[m][n-1]);
	return 0;
}