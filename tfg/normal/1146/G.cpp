#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T = int>
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
			pt = std::vector<int>(n, 0);
			while(flow = dfs(src, sink)) {
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
	int n, h, m;
	std::cin >> n >> h >> m;
	Dinic<int> graph(m + n * h + 2);
	int src = m + n * h;
	int sink = src + 1;
	// edges for n * h
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < h; j++) {
			graph.addEdge(m + i * h + j, sink, 2 * j + 1);
			if(j) {
				graph.addEdge(m + i * h + j - 1, m + i * h + j, 1e8);
			}
		}
	}
	// m things
	for(int x = 0; x < m; x++) {
		int l, r, lim, cost;
		std::cin >> l >> r >> lim >> cost;
		if(lim == h) continue;
		l--;
		for(int i = l; i < r; i++) {
			graph.addEdge(x, m + i * h + lim, 1e8);
		}
		graph.addEdge(src, x, cost);
	}
	std::cout << h * h * n - graph.maxFlow(src, sink) << '\n';
}