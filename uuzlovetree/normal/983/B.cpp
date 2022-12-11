#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int n,q;
int a[maxn];
int dp[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int l=n;l>=1;--l)
		for(int r=1;r<=n;++r)
		{
			if(l==r)dp[l][r]=a[l];
			else dp[l][r]=dp[l][r-1]^dp[l+1][r];
		}
	for(int l=n;l>=1;--l)
		for(int r=1;r<=n;++r)if(l!=r)
		{
			dp[l][r]=max(dp[l][r],max(dp[l+1][r],dp[l][r-1]));
		}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",dp[l][r]);
	}
	return 0;
}