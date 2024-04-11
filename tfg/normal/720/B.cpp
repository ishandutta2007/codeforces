#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct BCC {
public:
	BCC(int _n = 0) : n(_n) {
		edges.resize(n);
		low.assign(n, -1);
		cur.assign(n, -1);
		down.assign(n, -1);
		group.assign(n, -1);
	}

	void addEdge(int u, int v) {
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	void init() {
		for(int i = 0, c = 0; i < n; i++) {
			if(low[i] == -1) {
				dfs(i, c, -1);
			}
		}
	}

	int getGroup(int u, int v) {
		if(cur[u] < cur[v]) std::swap(u, v);
		return group[u] == group[v] || low[u] == cur[v] ? group[u] : -1;
	}
	bool isArt(int u) { return down[cur[u]] == -1; }
private:
	int n;
	std::vector<std::vector<int>> edges;
	std::vector<int> low, cur, down, group;

	void dfs(int on, int &c, int par) {
		cur[on] = c;
		low[on] = c++;
		int children = 0;
		bool root = par == -1;
		bool isArt = false;
		for(auto to : edges[on]) {
			if(to == par) {
				par = -1;
			} else if(low[to] == -1) {
				children++;
				down[cur[on]] = to;
				dfs(to, c, on);
				low[on] = std::min(low[on], low[to]);
				if((root && children > 1) || (!root && low[to] >= cur[on])) {
					isArt = true;
				}
			} else {
				low[on] = std::min(low[on], cur[to]);
			}
		}
		group[on] = down[low[on]];
		down[cur[on]] = isArt ? -1 : 0;
	}
};

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			//for(int i = 0; i < n; i++) {
			//	std::random_shuffle(edges[i].begin(), edges[i].end());
			//}
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap = 1) {
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
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
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
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> groups(n);
	struct Edge {
		Edge(int a, int b, int col) : u(a), v(b), c(col) {}
		int u, v, c;
	};
	std::vector<Edge> edges;
	BCC graph(n);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;c--;
		edges.emplace_back(u, v, c);
		graph.addEdge(u, v);
	}
	graph.init();
	Dinic<int> net(n+m+2);
	int src = n+m, sink = n+m+1;
	for(auto e : edges) {
		assert(e.c < m);
		int g = graph.getGroup(e.u, e.v);
		if(g == -1) {
			net.addEdge(src, e.c, 1);
		} else {
			groups[g].push_back(e.c);
		}
	}
	for(int i = 0; i < m; i++) {
		net.addEdge(i, sink, 1);
	}
	for(int i = 0; i < n; i++) {
		if((int) groups[i].size() <= 1) continue;
		net.addEdge(src, m+i, (int) groups[i].size() - 1);
		for(auto c : groups[i]) {
			net.addEdge(m+i, c, 1);
		}
	}
	std::cout << net.maxFlow(src, sink) << '\n';
}