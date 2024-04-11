#include <stdio.h>
#include <map>
using namespace std;
const int mod=1e9+7;
const int N=350;
int c[2*N][2*N],dp[N][N],b[N];
int f[N];
map<int,int> bucket;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j,a;
	scanf("%i",&n);
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a);
		for(j=2;j*j<=a;j++) while(a%(j*j)==0) a/=j*j;
		bucket[a]++;
		f[i]=((long long)f[i-1]*i)%mod;
	}
	for(i=0;i<2*n;i++)
	{
		c[i][0]=1;
		for(j=1;j<=i;j++)
		{
			c[i][j]=((long long)c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	int m=0,k,l,s=0;
	long long sol=1;
	map<int,int>::iterator it;
	for(it=bucket.begin();it!=bucket.end();it++) b[++m]=it->second;
	dp[0][0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(dp[i][j]>0)
			{
				for(k=1;k<=b[i+1];k++)
				{
					for(l=0;l<=min(j,k);l++)
					{
						long long tmp=((long long)dp[i][j]*c[j][l])%mod;
						tmp=(tmp*c[s+1-j][k-l])%mod;
						tmp=(tmp*c[b[i+1]-1][k-1])%mod;
						dp[i+1][j+b[i+1]-k-l]=((long long)dp[i+1][j+b[i+1]-k-l]+tmp)%mod;
					}
				}
			}
		}
		s+=b[i+1];
		sol=((long long)sol*f[b[i+1]])%mod;
	}
	printf("%lld\n",(sol*dp[m][0])%mod);
	return 0;
}