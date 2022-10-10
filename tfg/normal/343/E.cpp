#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
		T scale = 0;
		for(auto e : list) scale = std::max(scale, e.cap);
		scale = 1;
		for(; scale > 0; scale /= 2) {
			while(bfs(src, sink, scale)) {
				// maybe random shuffle edges against bad cases?
				T flow;
				pt = std::vector<int>(n, 0);
				while((flow = dfs(src, sink, std::numeric_limits<T>::max(), scale))) {
					ans += flow;
				}
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap = 1, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow, T scale) {
		if(flow < scale) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap), scale);
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink, T scale) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap < scale) {
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

struct Edge {
	Edge() {}
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
	int u, v;
	int c;
};

template<class T>
std::vector<Edge> gomoryHu(Dinic<T> graph) {
	std::vector<Edge> tree;
	int n = (int) graph.size();
	std::vector<int> par(n, 0);
	for(int i = 1; i < n; i++) {
		auto curGraph = graph;
		tree.emplace_back(i, par[i], curGraph.maxFlow(i, par[i]));
		for(int j = i+1; j < n; j++) {
			if(par[j] == par[i] && curGraph.inCut(j)) {
				par[j] = i;
			}
		}
	}
	return tree;
}

const int ms = 202;
int par[ms];
std::vector<int> wtf[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	assert(a != b);
	for(auto v : wtf[b]) wtf[a].push_back(v);
	wtf[b].clear();
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	Dinic<int> graph(n);
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		graph.addEdge(u, v, c, c);
	}
	auto tree = gomoryHu(graph);
	for(int i = 0; i < n; i++) {
		wtf[i].push_back(i);
		par[i] = i;
	}
	std::sort(tree.begin(), tree.end(), [](auto v1, auto v2) { return v1.c > v2.c; });
	long long ans = 0;
	for(auto edge : tree) {
		makeUnion(edge.u, edge.v);
		ans += edge.c;
	}
	std::cout << ans << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << wtf[getPar(0)][i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}