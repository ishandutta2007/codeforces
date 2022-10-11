#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class SuffixArray {
public:
	std::vector<int> buildSuffix(const std::vector<T> &array) {
		int n = array.size();
		std::vector<int> sa(n);
		for(int i = 0; i < n; i++) {
			sa[i] = i;
		}
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return array[a] < array[b]; });
		int cur = 0;
		std::vector<int> inv(n);
		std::vector<int> nxt(n);
		inv[sa[0]] = 0;
		for(int i = 1; i < n; i++) {
			inv[sa[i]] = (array[sa[i - 1]] != array[sa[i]] ? ++cur : cur);
		}
		cur++;
		for(int k = 0; cur < n; k++) {
			cur = 0;
			auxSort(sa, inv, 1 << k);
			for(int l = 0, r = 0; l < n; l = r, cur++) {
				while(r < n && getPair(inv, sa[l], 1 << k) == getPair(inv, sa[r], 1 << k)) {
					nxt[sa[r++]] = cur;
				}
			}
			nxt.swap(inv);
		}
		return sa;
	}

	std::vector<int> buildLCP(const std::vector<int> &sa, const std::vector<T> &array) {
		int n = sa.size();
		std::vector<int> inv(n);
		for(int i = 0; i < n; i++) {
			inv[sa[i]] = i;
		}
		std::vector<int> lcp(n, 0);
		for(int i = 0, k = 0; i < n; i++) {
			if(inv[i] + 1 == n) {
				k = 0;
				continue;
			}
			int j = sa[inv[i] + 1];
			while(i + k < n && j + k < n && array[i + k] == array[j + k]) {
				k++;
			}
			lcp[inv[i]] = k;
			if(k > 0) {
				k--;
			}
		}
		return lcp;
	}
private:
	void auxSort(std::vector<int> &sa, const std::vector<int> &inv, int offset) {
		// O(nlogn) step, O(nlog^2n) total
		std::sort(sa.begin(), sa.end(), [&](int a, int b) { return getPair(inv, a, offset) < getPair(inv, b, offset); });
		// O(n) step, O(nlogn) total -- TO DO --
	}
	std::pair<int, int> getPair(const std::vector<int> &inv, int pos, int offset) {
		return std::pair<int, int>(inv[pos], pos + offset < inv.size() ? inv[pos + offset] : -1);
	}
};

struct Merger {
	int operator() (int a, int b) { return std::min(a, b); }
};

template <class T, class Merger>
class SparseTable {
public:
	void init(std::vector<T> a) {
		int e = 0;
		int n = a.size();
		while((1 << e) / 2 < a.size()) {
			e++;
		}
		get.assign(n + 1, -1);
		for(int i = 0; i < n; i++) {
			table[0][i] = a[i];
			get[i+1] = get[(i+1)/2] + 1;
		}
		for(int i = 0; i + 1 < e; i++) {
			for(int j = 0; j + (1 << i) < n; j++) {
				table[i+1][j] = merge(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	
	T qry(int l, int r) {
		int e = get[r - l];
		return merge(table[e][l], table[e][r - (1 << e)]);
	}
private:
	T table[21][1001000];
	std::vector<int> get;
	Merger merge;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = i;
		std::cin >> a[i];
	}
	if(n == 1) {
		std::cout << 1 << "\n";
		std::cout << 2 * a[0] % m << '\n';
		return 0;
	}
	std::vector<int> b;
	for(int i = 0; i < 2 * n; i++) {
		int l = i % n;
		int r = (i + 1) % n;
		//std::cout << "for pos " << i << ", " << i + 1 << " got " << a[r] - a[l] << "\n";
		b.push_back((a[r] - a[l] + m) % m);
	}
	b.push_back(-1);
	std::vector<int> weird(n, 0);
	for(int i = 0; i < 2 * n; i++) {
		int l = (n - 1 - i + n + n) % n;
		int r = (l - 1 + n) % n;
		b.push_back((a[l] - a[r] + m) % m);
		if(i < n) {
			weird[n - i - 1] = (int) b.size() - 1;
		}
	}
	for(auto v : b) {
		//std::cout << v << ' ';
	}//std::cout << std::endl;
	SuffixArray<int> builder;
	auto sa = builder.buildSuffix(b);
	auto lcp = builder.buildLCP(sa, b);
	std::vector<int> inv(b.size());
	for(int i = 0; i < (int) b.size(); i++) {
		inv[sa[i]] = i;
	}
	std::vector<int> ans;
	// do stuff
	SparseTable<int, Merger> table;
	table.init(lcp);
	// first test
	for(int i = 0; i < n; i++) {
		int go = inv[i];
		int back = inv[weird[(i + 1) % n]];
		int l = std::min(go, back);
		int r = std::max(go, back);
		//std::cout << "lcp on " << i << " for first case is " << table.qry(l, r) << std::endl;
		if(table.qry(l, r) >= n - 1) {
			ans.push_back((a[i] + a[(i + 1) % n]) % m);
		}
	}
	// second test
	for(int i = 0; i < n; i++) {
		int go = inv[i];
		int back = inv[weird[i]];
		int l = std::min(go, back);
		int r = std::max(go, back);
		//std::cout << "lcp on " << i << " for second case is " << table.qry(l, r) << std::endl;
		if(table.qry(l, r) >= n - 1) {
			ans.push_back((a[i] + a[i]) % m);
		}
	}
	// print answer
	std::sort(ans.begin(), ans.end());
	ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}