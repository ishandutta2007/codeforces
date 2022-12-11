#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
int n;
ll a[maxn];
ll dp[maxn][3][2];
const ll inf = (ll)1e18;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	if(n==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<2;++k)dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<2;++k)
			{
				int p;
				p=k;
				if((j+1)%3==2)p=1;
				dp[i+1][(j+1)%3][p]=max(dp[i+1][(j+1)%3][p],dp[i][j][k]+a[i+1]);
				p=k;
				if((j+2)%3==2)p=1;
				dp[i+1][(j+2)%3][p]=max(dp[i+1][(j+2)%3][p],dp[i][j][k]-a[i+1]);
			}
	cout<<dp[n][1][1]<<endl;
}