#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <utility>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1e6;

template <class T>
class FenwickTree {
public:
	void init(int s) {
		this->n = s;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::min(x, n);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		x = std::max(x, 1);
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};

std::vector<int> edges[ms];
int h[ms], in[ms], out[ms], tim = 1;

void pre(int on, int par = -1) {
	if(on >= ms || on < 0 || in[on] > 0) {
		return;
	}
	in[on] = tim++;
	for(auto to : edges[on]) {
		if(to != par) {
			h[to] = 1 + h[on];
			pre(to, on);
		}
	}
	out[on] = tim;
	//std::cout << "on " << on + 1 << " got range [" << in[on] << ", " << out[on] << ") and h " << h[on] << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		//std::swap(u, v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	pre(0);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int a, int b) { return h[a] < h[b]; });
	int m;
	std::cin >> m;
	std::vector<std::pair<std::pair<int, int>, int>> qries(m, {std::pair<int, int>(0, 0), 0});
	for(int i = 0; i < m; i++) {
		int v, d, x;
		std::cin >> v >> d >> x;
		//std::cout << "reading (" << v << ", " << d << ", " << x << ")\n";
		v--;
		v = std::min(v, n-1);
		v = std::max(v, 0);
		d = std::min(d, n);
		qries[i].first.first = h[v] + d;
		qries[i].first.second = x;
		qries[i].second = v;
	}
	std::sort(qries.begin(), qries.end());
	int pt = 0;
	FenwickTree<long long> tree;
	tree.init(ms);
	for(auto q : qries) {
		while(pt < n && h[p[pt]] <= q.first.first) {
			long long v = tree.qry(in[p[pt]]);
			tree.upd(in[p[pt]], -v);
			tree.upd(in[p[pt]] + 1, v);
			pt++;
		}
		tree.upd(in[q.second], q.first.second);
		tree.upd(out[q.second], -q.first.second);
	}
	while(pt < n) {
		long long v = tree.qry(in[p[pt]]);
		tree.upd(in[p[pt]], -v);
		tree.upd(in[p[pt]] + 1, v);
		pt++;
	}
	for(int i = 0; i < n; i++) {
		std::cout << tree.qry(in[i]) << (i + 1 == n ? '\n' : ' ');
	}
}