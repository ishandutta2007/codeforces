#include <bits/stdc++.h>
using namespace std;

int c[100005], w[100005];
bool j[100005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);

	long long totaldis = 0;

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++)
	{
		if (c[i] % 100 == 0) continue;
		pq.emplace(-(w[i] * (100 - c[i] % 100)), i);
		while (m < c[i] % 100)
		{
			totaldis -= pq.top().first;
			j[pq.top().second] = true;
			pq.pop();
			m += 100;
		}

		m -= c[i] % 100;
	}

	printf("%lld\n", totaldis);
	for (int i = 0; i < n; i++)
	{
		if (j[i]) printf("%d 0\n", (c[i] + 99) / 100, 0);
		else printf("%d %d\n", c[i] / 100, c[i] % 100);
	}
}