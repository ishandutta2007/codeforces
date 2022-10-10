#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

template <class T>
class FenwickTree {
public:
	FenwickTree() {
		n = 0;
		bit.assign(1, 0);
	}

	void addPos() {
		bit.push_back(0);
		n++;
		bit.back() = qry(n-1) - qry(n);
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		while(x > n) {
			addPos();
		}
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}

	void swap(FenwickTree<T> &other) {
		std::swap(other.n, n);
		bit.swap(other.bit);
	}
private:
	int n;
	std::vector<T> bit;
};

struct Info {
	std::map<int, int> freq;
	FenwickTree<int> tree;

	void add(int x, int got) {
		int f = freq[x];
		freq[x] += got;
		if(f) tree.upd(f, -1);
		tree.upd(f + got, 1);
		size += got;
	}

	void swap(Info &o) {
		tree.swap(o.tree);
		freq.swap(o.freq);
		std::swap(size, o.size);
	}

	void merge(Info &o) {
		if(size < o.size) swap(o);
		for(auto it : o.freq) {
			add(it.first, it.second);
		}
	}

	int qry(int x) { return tree.qry(18273182) - tree.qry(x - 1); }

	int size = 0;
};

std::vector<int> edges[ms];
int c[ms];
std::vector<std::pair<int, int>> qries[ms];
int ans[ms];

void dfs(int on, int par, Info &info) {
	for(auto to : edges[on]) {
		if(to == par) continue;
		Info got;
		dfs(to, on, got);
		info.merge(got);
	}
	info.add(c[on], 1);
	for(auto qry : qries[on]) {
		ans[qry.first] = info.qry(qry.second);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i < m; i++) {
		int v, k;
		std::cin >> v >> k;
		v--;
		qries[v].emplace_back(i, k);
	}
	Info info;
	dfs(0, 0, info);
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}