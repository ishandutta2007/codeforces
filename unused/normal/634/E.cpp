#include "bits/stdc++.h"
using namespace std;

int val[200005];
vector<int> graph[200005];
int dp[200005];
int cnt[200005];
int cnt2[200005];
int n, k, mid, ans, total;

void dfs(int t, int p)
{
	int full = 0;
	cnt[t] = 1;
	cnt2[t] = (val[t] >= mid);
	vector<int> vt;
	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs(nxt, t);
		cnt[t] += cnt[nxt];
		cnt2[t] += cnt2[nxt];
		if (cnt[nxt] == dp[nxt]) full += dp[nxt];
		else 
		{
			vt.push_back(dp[nxt]);
		}
	}

	int upward = 1;
	if (total - cnt2[t] == n - cnt[t])
	{
		upward = n - cnt[t] + 1;
	}

	if (val[t] < mid)
	{
		dp[t] = 0;
		return;
	}

	sort(vt.begin(), vt.end());

	if (cnt[t] == full + 1 || vt.empty())
	{
		ans = max(ans, full + 1);
		dp[t] = full + 1;
		return;
	}
	else if (vt.size() == 1)
	{
		ans = max(ans, vt[0] + full + 1);
		dp[t] = vt[0] + full + 1;
		return;
	}
	else
	{
		ans = max(ans, vt.rbegin()[0] + vt.rbegin()[1] + full + upward);
		dp[t] = vt.back() + full + 1;
		return;
	}
}

bool check()
{
	ans = 0;
	total = 0;
	for (int i = 1; i <= n; i++) total += (val[i] >= mid);
	dfs(rand()%n+1, 0);
	return ans >= k;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++)
		scanf("%d",&val[i]);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int lo = 1, hi = 999999, a = 1000000;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check())
		{
			a = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	printf("%d", a);
}