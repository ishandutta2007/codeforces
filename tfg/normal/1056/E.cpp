#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <cassert>

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
		table.resize(e, std::vector<T>(n));
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
	std::vector<std::vector<T>> table;
	std::vector<int> get;
	Merger merge;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string p, t;
	std::cin >> p >> t;
	if(p.size() > t.size()) {
		std::cout << "0\n";
		return 0;
	}
	SuffixArray<char> builder;
	std::vector<char> tt(t.begin(), t.end());
	auto sa = builder.buildSuffix(tt);
	std::vector<int> inv(t.size());
	for(int i = 0; i < (int) t.size(); i++) {
		inv[sa[i]] = i;
	}
	auto lcp = builder.buildLCP(sa, tt);
	int f[2] = {0, 0};
	for(auto c : p) {
		f[c-'0']++;
	}
	int ans = 0;
	SparseTable<int, Merger> table;
	table.init(lcp);
	for(int i = 1; i * f[0] < (int) t.size(); i++) {
		int j = ((int) t.size() - i * f[0]) / f[1];
		if(i * f[0] + j * f[1] != (int) t.size()) {
			continue;
		}
		assert(j >= 1);
		//std::cout << "testing (" << i << ", " << f[0] << "), (" << j << ", " << f[1] << ")\n";
		int pos[2] = {-1, -1};
		int cur = 0;
		bool valid = true;
		for(auto c : p) {
			if(c == '0') {
				if(pos[0] == -1) {
					pos[0] = inv[cur];
				} else {
					int o = inv[cur];
					if(o > pos[0]) {
						std::swap(o, pos[0]);
					}
					valid = valid && table.qry(o, pos[0]) >= i;
				}
				cur += i;
			} else {
				if(pos[1] == -1) {
					pos[1] = inv[cur];
				} else {
					int o = inv[cur];
					if(o > pos[1]) {
						std::swap(o, pos[1]);
					}
					valid = valid && table.qry(o, pos[1]) >= j;
				}
				cur += j;
			}
			if(!valid) {
				cur = (int) t.size();
				break;
			}
		}
		assert(cur == (int) t.size());
		if(pos[0] > pos[1]) std::swap(pos[0], pos[1]);
		valid = valid && (i != j || table.qry(pos[0], pos[1]) < i);
		if(valid) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}