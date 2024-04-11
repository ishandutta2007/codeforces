#include <stdio.h>
#include <climits>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int dat[3005];
vector<long long> val;

long long dp[3005][3005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		dat[i] -= i;
		val.push_back(dat[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());

	for (int i = 0; i < val.size(); i++) dp[0][i] = abs(dat[0] - val[i]);

	for (int i = 1; i < n; i++)
	{
		long long mval = LLONG_MAX;
		for (int j = 0; j < val.size(); j++)
		{
			mval = min(mval, dp[i - 1][j]);
			dp[i][j] = mval + abs(dat[i] - val[j]);
		}
	}

	long long ans = LLONG_MAX;
	for (int i = 0; i < val.size(); i++) ans = min(ans, dp[n - 1][i]);
	printf("%lld", ans);
}