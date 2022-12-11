#include <bits/stdc++.h>
using namespace std;

int val[200005];
int par[200005];

long long total[200005];
long long dp[200005];
long long ans;
vector<int> tree[200005];

void dfs(int t)
{
	dp[t] = -1e18;
	total[t] = val[t];
	priority_queue<long long> pq;
	for (int nxt : tree[t])
	{
		if (nxt == par[t]) continue;
		par[nxt] = t;
		dfs(nxt);
		total[t] += total[nxt];
		pq.push(-dp[nxt]);
		dp[t] = max(dp[t], dp[nxt]);
		while (pq.size() > 2) pq.pop();
	}
	dp[t] = max(dp[t], total[t]);

	if (pq.size() == 2)
	{
		long long a = -pq.top();
		pq.pop();
		a -= pq.top();

		ans = max(ans, a);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &val[i]);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	ans = -1e18;

	dfs(0);

	if (ans <= (long long)-1e18) printf("Impossible");
	else printf("%lld", ans);
}