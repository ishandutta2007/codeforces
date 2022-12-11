#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100005];
long long weight[100005];

int main()
{
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int l;
	scanf("%d", &l);

	for (int i = 1; i <= n; i++) weight[i] = 1e18;
	priority_queue<pair<long long, int>> pq;
	pq.emplace(0, s);
	weight[s] = 0;

	int ans = 0;

	while (pq.empty() == false)
	{
		long long w = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (weight[v] < w) continue;
		if (w == l) ++ans;

		for (auto &&e : graph[v])
		{
			if (weight[e.first] > w + e.second)
			{
				weight[e.first] = w + e.second;
				pq.emplace(-weight[e.first], e.first);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (auto &&e : graph[i])
		{
			if (i > e.first) continue;

			long long small = min(weight[e.first], weight[i]), large = max(weight[e.first], weight[i]);

			if (large - small == e.second)
			{
				if (small < l && l < large) ++ans;
			}
			else
			{
				// x - large + x - small = e.second
				// x = (large + small + e.second) / 2

				long long twox = large + small + e.second;

				if (twox == l * 2) ++ans;
				else
				{
					if (small < l && 2 * l < twox) ++ans;
					if (large < l && 2 * l < twox) ++ans;
				}
			}
		}
	}

	printf("%d\n", ans);
}