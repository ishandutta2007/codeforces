#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
    
template <class T>
class FenwickTree {
public:
	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}

	void init(const std::vector<T> &a) {
		n = a.size();
		bit.assign(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
			if(i + (i & -i) <= n) {
				bit[i + (i & -i)] += bit[i];
			}
		}
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
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};

const int ms = 100100;

std::vector<int> pos[ms];
int pt[ms];
std::vector<std::pair<int, int> > qries[ms];
int ans[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] > n) {
			a[i] = -1;
		} else {
			pos[a[i]].push_back(i);
		}
	}
	FenwickTree<int> tree;
	tree.init(n + 10);
	for(int i = 1; i <= n; i++) {
		if(pos[i].size() >= i) {
			tree.upd(pos[i][i-1] + 1, 1);
		}
		if(pos[i].size() >= i+1) {
			tree.upd(pos[i][i] + 1, -1);
		}
	}
	for(int i = 0; i < m; i++) {
		int l, r;
		std::cin >> l >> r;
		qries[l-1].emplace_back(r, i);
	}
	for(int i = 0; i < n; i++) {
		for(auto qry : qries[i]) {
			ans[qry.second] = tree.qry(qry.first);
		}
		if(a[i] == -1) continue;
		// remove
		if(pt[a[i]] + a[i] <= pos[a[i]].size()) {
			tree.upd(pos[a[i]][pt[a[i]]+a[i]-1] + 1, -1);
		}
		if(pt[a[i]] + a[i] + 1 <= pos[a[i]].size()) {
			tree.upd(pos[a[i]][pt[a[i]]+a[i]] + 1, 1);
		}
		pt[a[i]]++;
		// add
		if(pt[a[i]] + a[i] <= pos[a[i]].size()) {
			tree.upd(pos[a[i]][pt[a[i]]+a[i]-1] + 1, 1);
		}
		if(pt[a[i]] + a[i] + 1 <= pos[a[i]].size()) {
			tree.upd(pos[a[i]][pt[a[i]]+a[i]] + 1, -1);
		}

	}
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}