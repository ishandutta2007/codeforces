#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Not dinic, ford fulkerson :P
template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int nn) {
		this->n = nn;
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		visit.assign(n, false);
		while(dfs(src, sink)) {
			ans++;
			visit.assign(n, false);
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
	std::vector<bool> visit;

	T dfs(int on, int sink) {
		if(visit[on]) {
			return 0;
		}
		visit[on] = true;
		if(on == sink) {
			return 1;
		}
		for(auto cur : edges[on]) {
			if(list[cur].cap == 0) continue;
			T got = dfs(list[cur].to, sink);
			if(got) {
				list[cur].cap -= 1;
				list[cur ^ 1].cap += 1;
				return got;
			}
		}
		return 0;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int src = m + n + 1;
	int sink = src + 1;
	std::vector<int> p(n), c(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i] = std::min(p[i], n);
	}
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
		c[i]--;
	}
	int d;
	std::cin >> d;
	std::vector<int> left(d);
	std::vector<bool> mark(n, false);
	for(int i = 0; i < d; i++) {
		std::cin >> left[i];
		left[i]--;
		mark[left[i]] = true;
	}
	Dinic<int> graph(m + n + 3);
	for(int i = 0; i < m; i++) {
		graph.addEdge(src, i, 1);
	}
	for(int i = 0; i < n; i++) {
		if(!mark[i]) {
			graph.addEdge(c[i], m + p[i], 1);
		}
	}
	int cur = 0;
	graph.addEdge(m, sink, 1);
	auto fix = [&]() {
		while(graph.maxFlow(src, sink)) {
			cur++;
			graph.addEdge(m + cur, sink, 1);
		}
	};
	fix();
	std::vector<int> ans(d);
	ans[d-1] = cur;
	for(int i = d-2; i >= 0; i--) {
		graph.addEdge(c[left[i+1]], m + p[left[i+1]], 1);
		fix();
		ans[i] = cur;
	}
	for(int i = 0; i < d; i++) {
		std::cout << ans[i] << '\n';
	}
}