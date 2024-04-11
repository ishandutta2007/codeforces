#include<bits/stdc++.h>
using namespace std;
const int max_n=500+5;
int a[max_n],b[max_n];
bool dp[max_n][max_n];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",a+i,b+i);
	long long sum=0;
	for(int i=1;i<=n;++i)
		sum+=a[i]+b[i];
	dp[0][0]=true;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=k-1;++j)
		{
			dp[i][j]|=dp[i-1][(j+k-a[i]%k)%k];
			for(int l=0;l<=min(k-1,a[i])&&!dp[i][j];++l)
			{
				if((a[i]-l)%k+b[i]>=k)
					dp[i][j]|=dp[i-1][(j+k-l)%k];
			}
		}
	for(int i=0;i<=k-1;++i)
	{
		if(dp[n][i])
		{
			printf("%lld\n",(sum-i)/k);
			return 0;
		}
	}
	puts("0");
	return 0;
}