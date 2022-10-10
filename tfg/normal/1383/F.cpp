#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
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

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow() {
		int src = 0, sink = n-1;
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

	void addEdge(int from, int to, T cap) {
		if(from == to || cap <= 0) return;
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

int n, m, k;
std::pair<int, int> special[10];
int val[10];
int cut[1 << 10], dp[1 << 10];
int INF;

void go(int on, int mask, Dinic<int> &graph, int flow) {
	if(on == k) {
		cut[mask] = flow;
	} else {
		int u = special[on].first, v = special[on].second;
		// being in the cut
		{
			auto other = graph;
			other.addEdge(0, u, INF);
			other.addEdge(v, n-1, INF);
			int newFlow = flow + other.maxFlow();
			go(on+1, mask | (1 << on), other, newFlow);
		}
		// not being in the cut
		{
			graph.addEdge(u, v, INF);
			int newFlow = flow + graph.maxFlow();
			go(on+1, mask, graph, newFlow);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> n >> m >> k >> q;
	INF = 26 * k;
	Dinic<int> graph(n);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		if(i < k) {
			special[i] = std::pair<int, int>(u, v);
		} else if(c != 0) {
			graph.addEdge(u, v, c);
		}
	}
	int baseFlow = graph.maxFlow();
	go(0, 0, graph, baseFlow);
	while(q--) {
		int ans = 1e9;
		for(int i = 0; i < k; i++) {
			std::cin >> val[i];
		}
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < (1 << i); j++) {
				dp[j | (1 << i)] = dp[j] + val[i];
			}
		}
		for(int i = 0; i < (1 << k); i++) {
			ans = std::min(ans, dp[i] + cut[i]);
		}
		std::cout << ans << '\n';
	}
}