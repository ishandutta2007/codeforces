#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long d, w;
	bool operator<(const node a)const
	{
		if (w == a.w)
		{
			return d > a.d;
		}
		return w > a.w;
	}
};
long long n, m, k, dp[100010][202];
vector<node> in[100010], out[100010];
void checkmin(long long &x, long long y)
{
	if (x > y)
	{
		x = y;
	}
}
int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= k; i++)
	{
		long long s, t;
		node temp;
		scanf("%lld%lld%lld%lld", &s, &t, &temp.d, &temp.w);
		in[s].push_back(temp);
		out[t].push_back(temp);
	}
	for (int i = 0; i <= 100001; i++)
	{
		for (int j = 0; j <= 200; j++)
		{
			dp[i][j] = 1e18;
		}
	}
	multiset<node> s;
	dp[1][0] = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		for (vector<node>::iterator it = in[i].begin(); it != in[i].end(); it++)
		{
			s.insert(*it);
		}
		for (int j = 0; j <= m; j++)
		{
			checkmin(dp[i + 1][j + 1], dp[i][j]);
			if (s.empty())
			{
				checkmin(dp[i + 1][j], dp[i][j]);
			}
			else
			{
				checkmin(dp[(*s.begin()).d + 1][j], dp[i][j] + (*s.begin()).w);
			}
		}
		for (vector<node>::iterator it = out[i].begin(); it != out[i].end(); it++)
		{
			s.erase(s.find(*it));
		}
	}
	long long ans = 1e18;
	for (int i = 0; i <= m; i++)
	{
		checkmin(ans, dp[n + 1][i]);
	}
	printf("%lld", ans);
	return 0;
}