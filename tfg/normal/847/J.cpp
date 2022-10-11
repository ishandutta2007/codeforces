#include <vector>
#include <queue>
#include <iostream>
#include <utility>

typedef std::pair<int, int> ii;

struct Edge
{
	Edge(int a, int b){to = a;cap = b;}
	int to, cap;
};

class Dinic
{
public:
	Dinic(int n)
	{
		edges.resize(n);
		this->n = n;
	}

	int maxFlow(int src, int sink)
	{
		int ans = 0;
		while(bfs(src, sink))
		{
			int flow;
			pt.assign(n, 0);
			while(flow = dfs(src, sink))
				ans += flow;
		}
		return ans;
	}

	void addEdge(int from, int to, int cap)
	{
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}

	std::vector<int> getEdges()
	{
		std::vector<int> ans;
		for(int i = 0; i < list.size(); i += 2)
		{
			if(list[i].cap == 0)
				ans.push_back(i / 2);
		}
		return ans;
	}

private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	int dfs(int on, int sink, int flow = 1e9)
	{
		if(flow == 0)
			return 0;
		if(on == sink)
			return flow;
		for(; pt[on] < edges[on].size(); pt[on]++)
		{
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to])
				continue;
			int got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got)
			{
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink)
	{
		h.assign(n, n + 10);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty())
		{
			int on = q.front();
			q.pop();
			for(auto a:edges[on])
			{
				if(list[a].cap == 0)
					continue;
				int to = list[a].to;
				if(h[to] > h[on] + 1)
				{
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] <= n;
	}
};

bool can(int n, int m, Dinic graph, int x)
{
	for(int i = 0; i < n; i++)
		graph.addEdge(i, n + m + 1, x);
	return graph.maxFlow(n + m, n + m + 1) == m;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	int src = n + m;
	int sink = src + 1;
	Dinic graph(n + m + 2);
	std::vector<ii> hmm;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		hmm.emplace_back(u, v);
		u--;
		v--;
		graph.addEdge(src, n + i, 1);
		graph.addEdge(n + i, u, 1);
		graph.addEdge(n + i, v, 1);
	}
	int l = 0, r = m;
	while(l != r)
	{
		int mid = (l + r) / 2;
		if(can(n, m, graph, mid))
			r = mid;
		else
			l = mid + 1;
	}
	for(int i = 0; i < n; i++)
		graph.addEdge(i, sink, l);
	graph.maxFlow(src, sink);
	std::vector<int> edges = graph.getEdges();
	std::cout << l << '\n';
	for(auto a : edges)
	{
		if(a < 3 * m)
		{
			if(a % 3 == 1)
				std::cout << hmm[a / 3].first << ' ' << hmm[a / 3].second << '\n';
			else if(a % 3 == 2)
				std::cout << hmm[a / 3].second << ' ' << hmm[a / 3].first << '\n';
		}
	}
}