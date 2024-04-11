#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
	int getSize(int x) { return -par[getPar(x)]; }
	int getPar(int x) {
		while(par[x] >= 0) {
			x = par[x];
		}
		return x;
	}

	void makeUnion(int a, int b) {
		a = getPar(a), b = getPar(b);
		if(a == b) return;
		if(par[a] > par[b]) std::swap(a, b);
		op.emplace_back(a, par[a]);
		op.emplace_back(b, par[b]);
		par[a] += par[b];
		par[b] = a;
	}

	void init(int n) {
		par.resize(n);
		for(int i = 0; i < n; i++) {
			par[i] = -1;
		}
		op.clear();
	}

	void rollBack() {
		par[op.back().first] = op.back().second;
		op.pop_back();
	}

	std::vector<int> par;
	std::vector<std::pair<int, int>> op;
};

struct Edge {
	int l, r, u, v;
};

const int ms = 500500;
std::vector<int> qries[ms];

DSU dsu;

void solve(int l, int r, std::vector<Edge> hmm) {
	int st = (int) dsu.op.size();
	std::vector<Edge> down;
	for(auto e : hmm) {
		if(e.r <= l || e.l >= r) {

		} else if(e.l <= l && r <= e.r) {
			dsu.makeUnion(e.u, e.v);
		} else {
			down.push_back(e);
		}
	}
	hmm.clear();
	if(l + 1 == r) {
		for(auto u : qries[l]) {
			std::cout << dsu.getSize(u) << '\n';
		}
	} else {
		int mid = (l + r) / 2;
		solve(l, mid, down);
		solve(mid, r, down);
	}
	while((int) dsu.op.size() > st) {
		dsu.rollBack();
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q, k;
	std::cin >> n >> q >> k;
	k--;
	dsu.init(n);
	std::vector<Edge> edges;
	std::vector<int> days(1, 0);
	for(int wtf = 0; wtf < q; wtf++) {
		int t;
		std::cin >> t;
		if(t == 1) {
			Edge cur;
			std::cin >> cur.u >> cur.v;
			cur.u--; cur.v--;
			cur.l = wtf;
			cur.r = (int) days.size() + k;
			edges.push_back(cur);
		} else if(t == 2) {
			int u;
			std::cin >> u;
			qries[wtf].push_back(u-1);
		} else {
			days.push_back(wtf);
		}
	}
	days.push_back(q);
	for(auto &e : edges) {
		e.r = days[std::min(e.r, (int) days.size() - 1)];
		//std::cout << "edge (" << e.u << ", " << e.v << ") in range [" << e.l << ", " << e.r << ")\n";
	}
	solve(0, q, edges);
}