#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
ll dp[2][N],h[2][N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&h[0][i]);
	for(int i=1;i<=n;i++) scanf("%lld",&h[1][i]);
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]+h[0][i]);
		dp[1][i]=max(dp[1][i-1],dp[0][i-1]+h[1][i]);
	}
	printf("%lld\n",max(dp[0][n],dp[1][n]));
	return 0;
}