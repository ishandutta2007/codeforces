#include <bits/stdc++.h>
using namespace std;
 
int n, m, q;
 
template <typename T, typename C>
class mcmf {
	public:
	static constexpr T eps = (T) 1e-9;
	struct edge {
		int from;
		int to;
		T c;
		T f;
		C cost;
	};
	vector< vector<int> > g;
	vector<edge> edges;
	vector<C> d;
	vector<int> q;
	vector<bool> in_queue;
	vector<int> pe;
	int n;
	int st, fin;
	T flow;
	C cost;
	mcmf(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
		assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
		g.resize(n);
		d.resize(n);
		in_queue.resize(n);
		pe.resize(n);
		flow = 0;
		cost = 0;
	}
	void clear_flow() {
		for (const edge &e : edges) {
			e.f = 0;
		}
		flow = 0;
	}
	 
	void add(int from, int to, T forward_cap, T backward_cap, C cost) {
		assert(0 <= from && from < n && 0 <= to && to < n);
		g[from].push_back((int) edges.size());
		edges.push_back({from, to, forward_cap, 0, cost});
		g[to].push_back((int) edges.size());
		edges.push_back({to, from, backward_cap, 0, -cost});
	}
	vector<C> c;
	bool expath() {
		fill(d.begin(), d.end(), numeric_limits<C>::max());
		q.clear();
		q.push_back(st);
		d[st] = 0;
		in_queue[st] = true;
		int beg = 0;
		bool found = false;
		while (beg < (int) q.size()) {
			int i = q[beg++];
			if (i == fin) {
				found = true;
			}
			in_queue[i] = false;
			for (int id : g[i]) {
				const edge &e = edges[id];
				if (e.c - e.f > eps && d[i] + e.cost < d[e.to]) {
					d[e.to] = d[i] + e.cost;
					pe[e.to] = id;
					if (!in_queue[e.to]) {
						q.push_back(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		if (found) {
			T push = numeric_limits<T>::max();
			int v = fin;
			while (v != st) {
				const edge &e = edges[pe[v]];
				push = min(push, e.c - e.f);
				v = e.from;
			}
			v = fin;
			while (v != st) {
				edge &e = edges[pe[v]];
				e.f += push;
				edge &back = edges[pe[v] ^ 1];
				back.f -= push;
				v = e.from;
			}
			flow += push;
			cost += push * d[fin];
			c.push_back(d[fin]);
		}
		return found;
	}
	 
	pair<T, C> max_flow_min_cost() {
		while (expath()) {
		}
		return make_pair(flow, cost);
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m;
	mcmf<int, int> g(n, 0, n-1);
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w, --u, --v;
		g.add(u, v, 1, 0, w);
	}
	g.max_flow_min_cost();
	g.c.push_back(g.c.back()+100001);
	cin >> q;
	cout << fixed << setprecision(9);
	for(int x; q--; ) {
		cin >> x;
		for(int i=0; ; ++i) {
			if(x<(g.c[i+1]-g.c[i])*(i+1)) {
				cout << g.c[i]+(double)x/(i+1) << "\n";
				break;
			}
			x-=(g.c[i+1]-g.c[i])*(i+1);
		}
	}
}