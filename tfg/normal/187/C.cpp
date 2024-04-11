#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
public:
	void init(int n) {
		par.resize(n);
		for(int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

	void makeUnion(int a, int b) {
		a = getPar(a);
		b = getPar(b);
		par[a] = b;
	}
private:
	std::vector<int> par;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> special(k);
	for(int i = 0; i < k; i++) {
		std::cin >> special[i];
		special[i]--;
	}
	std::vector<std::vector<int>> edges(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s, t;
	std::cin >> s >> t;
	s--;t--;
	int l = 0, r = n + 1;
	auto check = [&](int x) {
		DSU con;
		con.init(n);
		std::queue<int> q;
		std::vector<int> dist(n, (int) 1e9);
		std::vector<int> domin(n, -1);
		for(auto sp : special) {
			q.push(sp);
			domin[sp] = sp;
			dist[sp] = 0;
		}
		//std::cout << "testing for " << x << std::endl;
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			//std::cout << "on " << on << ", dist " << dist[on] << ", dom is " << domin[on] << std::endl;
			for(auto to : edges[on]) {
				if(dist[to] <= 1 + dist[on]) {
					// check to connect
					if(dist[on] + dist[to] + 1 <= x) {
						//std::cout << "connecting " << domin[on] << ", " << domin[to] << std::endl;
						con.makeUnion(domin[on], domin[to]);
					}
				} else {
					dist[to] = 1 + dist[on];
					domin[to] = domin[on];
					q.push(to);
				}
			}
		}
		dist.assign(n, (int) 1e9);
		for(auto sp : special) {
			if(con.getPar(sp) == con.getPar(s)) {
				dist[sp] = 0;
				q.push(sp);
			}
		}
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto to : edges[on]) {
				if(dist[to] <= 1 + dist[on]) {
					// do nothing
				} else {
					dist[to] = 1 + dist[on];
					q.push(to);
				}
			}
		}
		return dist[t] <= x;
	};
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if(l > n) {
		l = -1;
	}
	std::cout << l << '\n';
}