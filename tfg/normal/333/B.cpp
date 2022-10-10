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

	Dinic(int _n) {
		this->n = _n;
		edges.resize(n);
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
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> rows(n, false), cols(n, false);
	rows[0] = rows[n-1] = cols[0] = cols[n-1] = true;
	while(m--) {
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		rows[x] = cols[y] = true;
	}
	/*std::vector<int> dp(1 << 8, 0);
	std::vector<int> rest;
	rest.push_back(3);
	rest.push_back(3<<2);
	rest.push_back(3<<4);
	rest.push_back(3<<6);
	rest.push_back(5);
	rest.push_back(5 << 2);
	rest.push_back(5 << 4);
	rest.push_back(1 | (1 << 7));
	for(int i = 1; i < (1 << 8); i++) {
		int bits = 0;
		for(int j = 0; j < 8; j++) {
			if(i & (1 << j)) {
				bits++;
				dp[i] = std::max(dp[i], dp[i^(1<<j)]);
			}
		}
		bool valid = true;
		for(auto v : rest) {
			v = v & i;
			if(v != (v & -v)) {
				valid = false;
			}
		}
		if(valid) {
			dp[i] = bits;
		}
	}*/
	int ans = 0;
	for(int i = 1; i+1 < n; i++) {
		if(n % 2 == 1 && i == n / 2) {
			continue;
		}
		if(!rows[i]) {
			ans++;
		}
		if(!cols[i]) {
			ans++;
		}
	}
	if(n % 2 == 1 && (!rows[n/2] || !cols[n/2])) {
		ans++;
	}
	std::cout << ans << '\n';
}