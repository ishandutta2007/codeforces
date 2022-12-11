#include "bits/stdc++.h"
using namespace std;

pair<int, int> car[200005];
int gas[200005];
vector<int> dist;
long long tree[200005];
constexpr int TSIZE = 200004;
void add(int p, int val)
{
	for (; p <= TSIZE; p += p & -p)
		tree[p] += val;
}
long long query(int p)
{
	long long ret = 0;
	for (; p >= 1; p -= p & -p)
		ret += tree[p];
	return ret;
}

int main()
{
	int n, k, s, t;
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &car[i].first, &car[i].second);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &gas[i]);
	}

	sort(gas + 1, gas + 1 + k);
	gas[k + 1] = s;
	for (int i = 1; i <= k + 1; i++)
	{
		dist.push_back(gas[i] - gas[i - 1]);
	}

	sort(dist.begin(), dist.end());
	for (int i = 0; i < dist.size(); i++)
	{
		add(i + 1, dist[i]);
	}

	int ans = 2e9;

	for (int i = 0; i < n; i++)
	{
		if (dist.back() > car[i].second) continue;

		int idx = upper_bound(dist.begin(), dist.end(), car[i].second / 2) - dist.begin();

		long long sum1 = query(idx);
		long long sum2 = query(dist.size()) - sum1;

		if (sum1 + sum2 * 3 - car[i].second * 1ll * (dist.size() - idx) <= t)
			ans = min(ans, car[i].first);
	}

	if (ans > 1.5e9) printf("-1");
	else printf("%d", ans);
}