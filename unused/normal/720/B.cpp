#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <set>
#include <map>
#include <limits>
#include <queue>
using namespace std;

struct MaxFlowDinic {
	typedef int flow_t;
	struct Edge {
		int next;
		int inv; /* inverse edge index */
		flow_t res; /* residual */
	};
	int n;
	vector<vector<Edge>> graph;
	vector<int> q, l, start;
	void init(int _n) {
		n = _n;
		graph.resize(n);
		for (int i = 0; i < n; i++) graph[i].clear();
	}
	void add_edge(int s, int e, flow_t cap, flow_t caprev = 0) {
		Edge forward{ e, (int)graph[e].size(), cap };
		Edge reverse{ s, (int)graph[s].size(), caprev };
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}
	bool assign_level(int source, int sink) {
		int t = 0;
		memset(&l[0], 0, sizeof(l[0]) * l.size());
		l[source] = 1;
		q[t++] = source;
		for (int h = 0; h < t && !l[sink]; h++) {
			int cur = q[h];
			for (const auto& e : graph[cur]) {
				if (l[e.next] || e.res == 0) continue;
				l[e.next] = l[cur] + 1;
				q[t++] = e.next;
			}
		}
		return l[sink] != 0;
	}
	flow_t block_flow(int cur, int sink, flow_t current) {
		if (cur == sink) return current;
		for (int& i = start[cur]; i < graph[cur].size(); i++) {
			auto& e = graph[cur][i];
			if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
			if (flow_t res = block_flow(e.next, sink, min(e.res, current))) {
				e.res -= res;
				graph[e.next][e.inv].res += res;
				return res;
			}
		}
		return 0;
	}
	flow_t solve(int source, int sink) {
		q.resize(n);
		l.resize(n);
		start.resize(n);
		flow_t ans = 0;
		while (assign_level(source, sink)) {
			memset(&start[0], 0, sizeof(start[0]) * n);
			while (flow_t flow = block_flow(source, sink, numeric_limits<
				flow_t>::max()))
				ans += flow;
		}
		return ans;
	}
};

struct edge
{
	int s, e, c;
} edges[100005];

map<int, int> cnt;
map<int, int> color;
map<int, int> coloridx;
vector<set<int>> cycles;
vector<pair<int, int>> graph[10005];
pair<int, int> path[10005];

bool visit[10005];
bool now[10005];

void dfs(int t)
{
	for (auto &&e : graph[t])
	{
		if (path[t].first == e.first) continue;
		if (visit[e.first])
		{
			if (now[e.first] == false) continue;
			set<int> cycle;
			cycle.insert(e.second);
			color[e.second]++;

			int cnt = 0;
			for (int nod = t; nod != e.first; nod = path[nod].first)
			{
				cycle.insert(path[nod].second);
				color[path[nod].second]++;
			}

			cycles.emplace_back(move(cycle));
			continue;
		}

		visit[e.first] = true;
		now[e.first] = true;
		path[e.first] = { t, e.second };
		dfs(e.first);
		now[e.first] = false;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		edges[i] = {a, b, c};
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
		cnt[c]++;
	}

	visit[0] = true;
	now[0] = true;
	dfs(0);

	for (auto &elem : color)
	{
		coloridx.emplace(elem.first, coloridx.size() + 1);
	}

	MaxFlowDinic mf;
	mf.init(color.size() + cycles.size() + 2);
	for (int i = 0; i < cycles.size(); i++)
	{
		mf.add_edge(0, i + 1, 1);
		for (int j : cycles[i])
		{
			mf.add_edge(i + 1, coloridx[j] + cycles.size(), 1);
		}
	}
	for (auto &&c : color)
	{
		mf.add_edge(coloridx[c.first] + cycles.size(), color.size() + cycles.size() + 1, cnt[c.first] - 1);
	}
	printf("%d", (int)(cnt.size() - (cycles.size() - mf.solve(0, color.size() + cycles.size() + 1))));
}