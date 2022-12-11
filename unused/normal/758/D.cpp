#include <bits/stdc++.h>
using namespace std;

char str[1000];
int len, n;
pair<int, long long> dp[66];
bool visit[66];
constexpr long long inf = 2e18;
long long npow[1000];

pair<int, long long> D(int idx)
{
	if (idx >= len) return{ 0, 0 };
	if (visit[idx] == false)
	{
		visit[idx] = true;
		dp[idx].second = inf * 2;
		for (int right = idx + 1; right <= len; right++)
		{
			auto sub = stoll(string(str + idx, str + right));
			if (sub >= n) break;
			auto ret = D(right);
			if (npow[ret.first] == 0) continue;
			if (sub && npow[ret.first] > inf / sub) continue;
			ret.second += npow[ret.first] * sub;
			ret.first++;
			if (ret.second > inf) continue;

			if (dp[idx].second > ret.second)
				dp[idx] = ret;
		}
	}
	return dp[idx];
}

int main()
{
	scanf("%d%s", &n, str);
	len = strlen(str);

	npow[0] = 1;
	for (int i = 1; npow[i - 1] <= inf / n; i++)
		npow[i] = npow[i - 1] * n;

	printf("%lld", D(0).second);
}