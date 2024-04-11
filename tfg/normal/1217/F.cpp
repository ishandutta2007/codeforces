#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
	int getSize(int x) { return -getPar(x); }
	int getPar(int x) {
		int st = op.size();
		while(par[x] >= 0) {
			op.emplace_back(x, par[x]);
			x = par[x];
		}
		for(int i = st; i < (int) op.size(); i++) {
			par[op[i].first] = x;
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

std::vector<std::pair<int, int>> edges;

struct Query {
	int t, first, second;
	void read() {
		std::cin >> t >> first >> second;
	}
};

struct Edge {
	int id, l, r;
};

int last = 0;
Query qries[400200];
bool exists[400200];

DSU dsu;

int n;

void solve(int l, int r, std::vector<Edge> hmm) {
	int st = (int) dsu.op.size();
	std::vector<Edge> down;
	for(auto e : hmm) {
		if(e.r <= l || e.l >= r) {

		} else if(e.l <= l && r <= e.r) {
			if(exists[e.id]) {
				dsu.makeUnion(edges[e.id].first, edges[e.id].second);
			}
		} else {
			down.push_back(e);
			dsu.getPar(edges[e.id].first);
			dsu.getPar(edges[e.id].second);
		}
	}
	hmm.clear();
	if(l + 1 == r) {
		if(qries[l].t == 1) {
			std::pair<int, int> cur((qries[l].first - 1 + last) % n, (qries[l].second - 1 + last) % n);
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			int id = std::lower_bound(edges.begin(), edges.end(), cur) - edges.begin();
			exists[id] = !exists[id];
		} else {
			std::pair<int, int> cur((qries[l].first - 1 + last) % n, (qries[l].second - 1 + last) % n);
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			last = dsu.getPar(cur.first) == dsu.getPar(cur.second) ? 1 : 0;
			std::cout << last;
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
	int m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		qries[i].read();
		if(qries[i].t == 1) {
			std::pair<int, int> cur((qries[i].first - 1) % n, (qries[i].second - 1) % n);
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			edges.push_back(cur);
			cur.first = (cur.first + 1) % n;
			cur.second = (cur.second + 1) % n;
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			edges.push_back(cur);
		}
	}
	std::sort(edges.begin(), edges.end());
	edges.resize(std::unique(edges.begin(), edges.end()) - edges.begin());
	std::vector<int> from(edges.size(), -1);
	std::vector<Edge> ha;
	for(int i = 0; i < m; i++) {
		Edge lul;
		if(qries[i].t == 1) {
			int id;
			std::pair<int, int> cur((qries[i].first - 1) % n, (qries[i].second - 1) % n);
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			id = std::lower_bound(edges.begin(), edges.end(), cur) - edges.begin();
			lul.id = id;
			lul.l = from[id] + 1;
			lul.r = i;
			from[id] = i;
			ha.push_back(lul);
			cur.first = (cur.first + 1) % n;
			cur.second = (cur.second + 1) % n;
			if(cur.first > cur.second) std::swap(cur.first, cur.second);
			id = std::lower_bound(edges.begin(), edges.end(), cur) - edges.begin();
			lul.id = id;
			lul.l = from[id] + 1;
			lul.r = i;
			from[id] = i;
			ha.push_back(lul);
		}
	}
	for(int i = 0; i < (int) edges.size(); i++) {
		Edge lul;
		lul.id = i;
		lul.l = from[i] + 1;
		lul.r = m;
		ha.push_back(lul);
	}
	dsu.init(n);
	solve(0, m, ha);
	std::cout << std::endl;
}