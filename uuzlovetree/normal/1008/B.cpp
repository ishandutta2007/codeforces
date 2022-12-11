#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn];
int dp[maxn][2];
int main()
{
	scanf("%d",&n);
	a[0]=2e9;b[0]=2e9;
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i-1]>=a[i])dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
		if(a[i-1]>=b[i])dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
		if(b[i-1]>=a[i])dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
		if(b[i-1]>=b[i])dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
	}
	if(dp[n][0]==n||dp[n][1]==n)puts("YES");
	else puts("NO");
	return 0;
}