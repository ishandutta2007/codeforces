#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v;
	long long c;
};

struct Query {
	int u, v;
	int id;
	int l, r;
};

int par[100100];

void init() {
	for(int i = 0; i < 100100; i++) {
		par[i] = -1;
	}
}

int getPar(int x) { return par[x] < 0 ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return false;
	if(par[a] > par[b]) std::swap(a, b);
	par[b] = a;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k, q;
	std::cin >> n >> m >> k >> q;
	std::vector<std::vector<std::pair<int, long long>>> ed(n);
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		ed[u].emplace_back(v, c);
		ed[v].emplace_back(u, c);
	}
	const long long INF = 1e18;
	std::vector<int> rep(n, -1);
	std::vector<long long> dist(n, INF);
	std::vector<Edge> edges;
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> hp;
	for(int i = 0; i < k; i++) {
		dist[i] = 0;
		rep[i] = i;
		hp.push({0, i});
	}
	while(!hp.empty()) {
		int on = hp.top().second;
		long long curDist = hp.top().first;
		hp.pop();
		if(curDist != dist[on]) {
			continue;
		}
		//std::cout << "at " << on << " got dist " << dist[on] << " and rep is " << rep[on] << '\n';
		{
			Edge cur;
			cur.u = rep[on];
			cur.v = on;
			cur.c = curDist;
			edges.push_back(cur);
		}
		for(auto e : ed[on]) {
			int to = e.first;
			long long toDist = curDist + e.second;
			if(toDist < dist[to]) {
				dist[to] = toDist;
				rep[to] = rep[on];
				hp.push({toDist, to});
			} else {
				Edge cur;
				cur.u = rep[on];
				cur.v = rep[to];
				cur.c = dist[on] + dist[to] + e.second;
				edges.push_back(cur);
			}
		}
	}
	std::sort(edges.begin(), edges.end(), [&](Edge e1, Edge e2) { return e1.c < e2.c; });
	{
		std::vector<Edge> useful;
		init();
		for(auto e : edges) {
			if(makeUnion(e.u, e.v)) {
			//std::cout << e.u << ", " << e.v << ", " << e.c << "\n";
				useful.push_back(e);
			}
		}
		edges = useful;
	}
	assert((int) edges.size() == n - 1);
	std::vector<Query> qries;
	for(int i = 0; i < q; i++) {
		Query cur;
		cur.id = i;
		cur.l = 0;
		cur.r = n - 1;
		std::cin >> cur.u >> cur.v;
		cur.u--;
		cur.v--;
		qries.push_back(cur);
	}
	for(bool run = true; run; ) {
		run = false;
		std::sort(qries.begin(), qries.end(), [&](Query q1, Query q2) { return (q1.l + q1.r) / 2 < (q2.l + q2.r) / 2; });
		int pt = 0;
		init();
		for(auto &qry : qries) {
			if(qry.l == qry.r) {
				continue;
			}
			run = true;
			int mid = (qry.l + qry.r) / 2;
			while(pt < mid) {
				makeUnion(edges[pt].u, edges[pt].v);
				pt++;
			}
			if(getPar(qry.u) == getPar(qry.v)) {
				qry.r = mid;
			} else {
				qry.l = mid + 1;
			}
		}
	}
	std::sort(qries.begin(), qries.end(), [&](Query q1, Query q2) { return q1.id < q2.id; });
	for(auto qry : qries) {
		//std::cout << qry.l << ", " << qry.r << '\n';
		std::cout << edges[qry.l-1].c << '\n';
	}
}