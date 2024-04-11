#include <bits/stdc++.h>
using namespace std;
const int Maxn=5005;
int n,a[Maxn],b[Maxn],m,dp[Maxn][Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]) b[++m]=a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int l=1,r=l+i;r<=m;l++,r++)
		{
			if(b[l]==b[r]) dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
			else dp[l][r]=min(dp[l][r],min(dp[l][r-1]+1,dp[l+1][r]+1));
		}
	printf("%d",dp[1][m]);
	return 0;
}