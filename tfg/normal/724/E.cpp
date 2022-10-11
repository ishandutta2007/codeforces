#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
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

	Dinic(int nn) {
		edges.resize(nn);
		this->n = nn;
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

	T dfs(int on, int sink, T flow = 1e18) {
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
	int n;
	long long c;
	std::cin >> n >> c;
	std::vector<int> s(n), t(n), delta(n);
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> t[i];
	}
	std::vector<long long> prv(1, 0);
	for(int i = 0; i < n; i++) {
		const long long INF = 1e18;
		std::vector<long long> nxt(i + 2, INF);
		for(int j = 0; j <= i; j++) {
			// choosing this
			nxt[j+1] = std::min(nxt[j+1], prv[j] + t[i]);
			// not choosing this
			nxt[j] = std::min(nxt[j], prv[j] + s[i] + c * j);
		}
		prv.swap(nxt);
	}
	long long ans = 1e18;
	for(int i = 0; i <= n; i++) {
		ans = std::min(ans, prv[i]);
	}
	std::cout << ans << '\n';
}