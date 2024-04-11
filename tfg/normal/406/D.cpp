#include <iostream>
#include <vector>

typedef long long ll;

struct PT {
	typedef ll T;
	T x, y;
	int idx;
	PT(T x = 0, T y = 0) : x(x), y(y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
};

namespace BinaryLifting {
	const int ms = 100100;
	const int me = 18;
	int anc[me][ms];
	int h[ms];

	void dfs(const std::vector<std::vector<int>> &edges, int on, int par, int he = 0) {
		h[on] = he;
		anc[0][on] = par;
		for(auto to : edges[on]) {
			if(to != par) {
				dfs(edges, to, on, he + 1);
			}
		}
	}

	void init(const std::vector<std::vector<int>> &edges, int on = 0) {
		dfs(edges, on, on);
		for(int i = 1; i < me; i++) {
			for(int j = 0; j < edges.size(); j++) {
				anc[i][j] = anc[i-1][anc[i-1][j]];
			}
		}
	}

	int getLCA(int u, int v) {
		if(h[u] < h[v]) {
			std::swap(u, v);
		}
		int ans = h[u] - h[v];
		for(int i = me - 1; i >= 0; i--) {
			if((1 << i) & ans) {
				u = anc[i][u];
			}
		}
		if(u == v) {
			return u;
		}
		for(int i = me - 1; i >= 0; i--) {
			if(anc[i][u] != anc[i][v]) {
				ans += 1 << (i + 1);
				u = anc[i][u];
				v = anc[i][v];
			}
		}
		return anc[0][u];
	}

	int getDist(int u, int v) {
		int lca = getLCA(u, v);
		return h[u] + h[v] - 2 * h[lca];
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<PT> pts(n);
	for(int i = 0; i < n; i++) {
		std::cin >> pts[i].x >> pts[i].y;
		pts[i].idx = i;
	}
	std::vector<PT> hull(n, pts[n-1]);
	std::vector<std::vector<int>> graph(n);
	for(int i = n - 2, s = 1; i >= 0; i--) {
		while(s >= 2 && (hull[s - 2] - pts[i]) % (hull[s - 1] - hull[s - 2]) < 0) {
			s--;
		}
		int par = hull[s-1].idx;
		hull[s++] = pts[i];
		graph[par].push_back(i);
		graph[i].push_back(par);
	}
	BinaryLifting::init(graph, n-1);
	int m;
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		std::cout << BinaryLifting::getLCA(u - 1, v - 1) + 1 << (i + 1 == m ? '\n' : ' ');
	}
}