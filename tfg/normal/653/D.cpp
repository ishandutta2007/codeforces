#include <iostream>
#include <utility>
#include <vector>
#include <queue>

typedef long long ll;

template <class T>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int n) {
		edges.resize(n);
		this->n = n;
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			T flow;
			pt.assign(n, 0);
			while(flow = dfs(src, sink)) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}

private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n + 10);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a:edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

#include <iomanip>

int main() {
	int n, m, x;
	std::cin >> n >> m >> x;
	std::vector< std::pair<ll, std::pair<int, int> > > edges;
	ll frac = 1e7;
	for(int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges.emplace_back(c * frac, std::pair<int, int> (u, v));
	}
	ll l = 0, r = 1e14;
	while(l != r) {
		ll mid = (l + r + 1) / 2;
		Dinic<ll> graph(n + 2);
		int src = n;
		int sink = src + 1;
		graph.addEdge(src, 0, x);
		graph.addEdge(n - 1, sink, x);
		for(auto e : edges) {
			graph.addEdge(e.second.first, e.second.second, e.first / mid);
		}
		if(graph.maxFlow(src, sink) == x) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << std::fixed << std::setprecision(20) << l * x / 1e7 << std::endl;
}