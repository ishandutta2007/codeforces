#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

typedef std::pair<int, int> ii;

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

std::vector<ii> divs(int n) {
	std::vector<ii> ans;
	for(int i = 2; i * i <= n; i++) {
		int f = 0;
		while(n % i == 0) {
			n /= i;
			f++;
		}
		if(f) {
			ans.emplace_back(i, f);
		}
	}
	if(n > 1) {
		ans.emplace_back(n, 1);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::map<int, std::map<int, int>> freqs;
	std::vector<ii> edges;
	Dinic<int> base(n + 2);
	int src = n, sink = n + 1;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		if(u % 2 == 1) {
			std::swap(u, v);
		}
		edges.emplace_back(u, v);
		base.addEdge(u, v, 100);
	}
	for(int i = 0; i < n; i++) {
		auto v = divs(a[i]);
		for(auto d : v) {
			freqs[d.first][i] = d.second;
		}
	}
	int ans = 0;
	for(auto g : freqs) {
		Dinic<int> graph = base;
		//std::cout << "for " << g.first << std::endl;
		for(auto f : g.second) {
			int u = f.first;
			int c = f.second;
			//std::cout << "cap " << c << ", ";
			if(u % 2 == 0) {
				//std::cout << "adding first type for " << u << std::endl;
				graph.addEdge(src, u, c);
			} else {
				//std::cout << "adding second type for " << u << std::endl;
				graph.addEdge(u, sink, c);
			}
		}
		ans += graph.maxFlow(src, sink);
	}
	std::cout << ans << std::endl;
}