#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

template <class T, class C = std::less<T>>
struct MaxQueue {
	MaxQueue() {
		clear();
	}

	void clear() {
		id = 0;
		q.clear();
		sum = 0;
	}

	void push(T x, int f = 1) {
		std::pair<int, T> nxt(f, x);
		//std::cout << "pushing " << x << "\n";
		while(q.size() > id && cmp(q.back().second, x)) {
			//std::cout << "popping " << q.back().second << "\n";
			nxt.first += q.back().first;
			sum -= (long long) q.back().first * q.back().second;
			q.pop_back();
		}
		q.push_back(nxt);
		sum += (long long) nxt.first * nxt.second;
	}

	T qry() {
		return q[id].second;
	}

	void pop() {
		q[id].first--;
		if(q[id].first == 0) {
			id++;
		}
	}

	long long sum;
private:
	std::vector<std::pair<int, T>> q;
	int id;
	C cmp;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::vector<char> str(n);
	for(int i = 0; i < n; i++) {
		std::cin >> str[i];
	}
	SuffixArray<char> builder;
	auto sa = builder.buildSuffix(str);
	auto lcp = builder.buildLCP(sa, str);
	std::vector<int> inv(n, -1);
	for(int i = 0; i < n; i++) {
		inv[sa[i]] = i;
	}
	SparseTable<int, Merger> table;
	table.init(lcp);
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		std::vector<int> ord1(l);
		std::vector<int> ord2(r);
		for(int i = 0; i < l; i++) {
			std::cin >> ord1[i];
			ord1[i]--;
		}
		for(int i = 0; i < r; i++) {
			std::cin >> ord2[i];
			ord2[i]--;
		}
		std::sort(ord2.begin(), ord2.end(), [&](int a, int b) { return inv[a] < inv[b]; });
		std::sort(ord1.begin(), ord1.end(), [&](int a, int b) { return inv[a] < inv[b]; });
		long long ans = 0;
		//std::cout << "a is:"; for(auto v : ord1) std::cout << ' ' << v; std::cout << '\n';
		//std::cout << "b is:"; for(auto v : ord2) std::cout << ' ' << v; std::cout << '\n';
		{
			//solving from left to right
			//std::cout << "first case\n";
			MaxQueue<int, std::greater<int>> que;
			for(int i = 0, j = 0; i < l; i++) {
				if(i > 0) {
					que.push(table.qry(inv[ord1[i - 1]], inv[ord1[i]]), 0);
				}
				while(j < r && inv[ord2[j]] < inv[ord1[i]]) {
					que.push(table.qry(inv[ord2[j]], inv[ord1[i]]));
					j++;
				}
				ans += que.sum;
			}
		}
		{
			//solving from right to left
			//std::cout << "second case\n";
			MaxQueue<int, std::greater<int>> que;
			std::swap(l, r);
			std::swap(ord1, ord2);
			for(int i = 0, j = 0; i < l; i++) {
				if(i > 0) {
					que.push(table.qry(inv[ord1[i - 1]], inv[ord1[i]]), 0);
				}
				while(j < r && inv[ord2[j]] < inv[ord1[i]]) {
					que.push(table.qry(inv[ord2[j]], inv[ord1[i]]));
					j++;
				}
				if(j < r && ord2[j] == ord1[i]) {
					ans += n - ord2[j];
				}
				ans += que.sum;
			}
		}
		std::cout << ans << '\n';
	}
}