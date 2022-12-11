#include <stdio.h>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, s, t;

struct edge
{
	int u, v, w;
};
edge dat[10005];
vector<int> graph[1005];
int weight[1005];

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &dat[i].u, &dat[i].v, &dat[i].w);
		graph[dat[i].u].push_back(i);
		graph[dat[i].v].push_back(i);
	}

	int below = 2e9, above = -2e9;
	int lo = 1, hi = l;
	while (lo <= hi)
	{
		auto mid = (lo + hi) / 2;

		for (int i = 0; i < n; i++) weight[i] = (int)1e9 + 1;
		weight[s] = 0;

		priority_queue<pair<int, int>> pq;
		pq.emplace(0, s);

		while (pq.empty() == false)
		{
			int w, v;
			tie(w, v) = pq.top();
			w = -w;
			pq.pop();
			if (weight[v] < w) continue;
			if (v == t) break;

			for (int e : graph[v])
			{
				int nv = dat[e].u == v ? dat[e].v : dat[e].u;
				int nw = w + (dat[e].w ? dat[e].w : mid);
				if (nw > l) continue;
				if (weight[nv] > nw)
				{
					weight[nv] = nw;
					pq.emplace(-nw, nv);
				}
			}
		}

		if (weight[t] > l)
		{
			above = mid;
			hi = mid - 1;
		}
		else if (weight[t] == l)
		{
			printf("YES\n");
			for (int i = 0; i < m; i++) printf("%d %d %d\n",
				dat[i].u, dat[i].v, dat[i].w ? dat[i].w : (int)mid);
			return 0;
		}
		else
		{
			below = mid;
			lo = mid + 1;
		}
	}
	if (below >= above)
	{
		printf("NO\n");
		return 0;
	}
	int stick = below;
	printf("YES\n");

	lo = 0, hi = m - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;

		for (int i = 0; i < n; i++) weight[i] = (int)1e9 + 1;
		weight[s] = 0;

		priority_queue<pair<int, int>> pq;
		pq.emplace(0, s);

		while (pq.empty() == false)
		{
			int w, v;
			tie(w, v) = pq.top();
			w = -w;
			pq.pop();
			if (weight[v] < w) continue;
			if (v == t) break;

			for (int e : graph[v])
			{
				int nv = dat[e].u == v ? dat[e].v : dat[e].u;
				int nw = w + (dat[e].w ? dat[e].w : (e <= mid ? stick + 1 : stick));
				if (nw > l) continue;
				if (weight[nv] > nw)
				{
					weight[nv] = nw;
					pq.emplace(-nw, nv);
				}
			}
		}

		if (weight[t] > l)
		{
			hi = mid - 1;
		}
		else if (weight[t] == l)
		{
			for (int i = 0; i < m; i++) printf("%d %d %d\n",
				dat[i].u, dat[i].v, dat[i].w ? dat[i].w : (i <= mid ? stick + 1 : stick));
			return 0;
		}
		else
		{
			lo = mid + 1;
		}
	}

}