#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

D dp[1001][1001];
D res;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	scanf("%d%d", &n, &m);
	dp[1][1]=1;
	for(int t=2; t<=n; t++)
	{
		for(int il=1; il<=m; il++)
		{
			dp[t][il]=dp[t-1][il-1]*(D)(m-il+1)/(D)(n*m-t+1)+dp[t-1][il]*(D)(n*m-(m+t-1-il))/(D)(n*m-t+1);
		//	printf("%lf\n", dp[t][il]);
		}
	}
	for(int i=1; i<=m; i++) res+=dp[n][i]*((D)i/(D)n);
	printf("%lf\n", res);
	return 0;
}