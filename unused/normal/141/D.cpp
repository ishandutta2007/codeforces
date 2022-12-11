#include <bits/stdc++.h>
using namespace std;

vector<int> pts;

struct jump
{
	int x, d, t, p;
};

jump dat[100005];

struct edge
{
	int e, w, idx;
};
vector<edge> graph[300005];
long long weight[300005];
pair<int, int> path[300005];

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	pts.push_back(0);
	pts.push_back(l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &dat[i].x, &dat[i].d, &dat[i].t, &dat[i].p);
		if (dat[i].x < dat[i].p)
		{
			continue;
		}
		pts.push_back(dat[i].x - dat[i].p);
		pts.push_back(dat[i].x + dat[i].d);
	}

	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());

	for (int i = 1; i < pts.size(); i++)
	{
		graph[i - 1].push_back({ i, pts[i] - pts[i - 1], -1 });
		graph[i].push_back({ i - 1, pts[i] - pts[i - 1], -1 });
		weight[i] = 1e18;
	}

	for (int i = 0; i < n; i++)
	{
		if (dat[i].x < dat[i].p)
		{
			continue;
		}
		int idx1 = lower_bound(pts.begin(), pts.end(), dat[i].x - dat[i].p) - pts.begin();
		int idx2 = lower_bound(pts.begin(), pts.end(), dat[i].x + dat[i].d) - pts.begin();
		graph[idx1].push_back({ idx2, dat[i].p + dat[i].t, i });
	}

	priority_queue<pair<long long, int>> pq;
	pq.emplace(0, 0);
	weight[0] = 0;

	while (pq.empty() == false)
	{
		long long w; int v;
		tie(w, v) = pq.top();
		pq.pop();
		w = -w;
		if (weight[v] < w) continue;

		if (v == pts.size() - 1) break;

		for (auto &&e : graph[v])
		{
			long long nw = w + e.w;
			if (weight[e.e] > nw)
			{
				weight[e.e] = nw;
				path[e.e] = { v, e.idx };
				pq.emplace(-nw, e.e);
			}
		}
	}

	vector<int> vt;
	for (int now = pts.size() - 1; now; now = path[now].first)
	{
		if (path[now].second >= 0) vt.push_back(path[now].second + 1);
	}

	printf("%lld\n%zd\n", weight[pts.size() - 1], vt.size());
	for (int i = (int)vt.size() - 1; i >= 0; i--) printf("%d\n", vt[i]);
}