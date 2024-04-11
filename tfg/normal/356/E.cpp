#include <iostream>
#include <vector>
#include <chrono>
#include <random>
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
		if(l > r) std::swap(l, r);
		int e = get[r - l];
		return merge(table[e][l], table[e][r - (1 << e)]);
	}
private:
	std::vector<std::vector<T>> table;
	std::vector<int> get;
	Merger merge;
};

std::string str;
std::vector<int> sa, lcp, rev;
int n;
SparseTable<int, Merger> table;

const int ms = 100100;
const int me = 19;

long long tot = 0;
long long cost[ms][26];
long long sum[ms];

bool dp[me][ms];
int mask[me][ms];

long long f(long long x) { return x * x; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> str;
	n = (int) str.size();
	{
		std::vector<char> wtf(str.begin(), str.end());
		SuffixArray<char> builder;
		sa = builder.buildSuffix(wtf);
		lcp = builder.buildLCP(sa, wtf);
		rev.resize(n);
		for(int i = 0; i < n; i++) {
			rev[sa[i]] = i;
		}
		table.init(lcp);
	}
	int size = 0;
	for(int i = 0; i < n; i++) {
		dp[0][i] = true;
		tot++;
		mask[0][i] = 1 << (str[i] - 'a');
	}
	size++;
	for(int i = 1; i < me; i++) {
		for(int j = size; j + size < n; j++) {
			//std::cout << "at " << i << ", " << j << " size " << size << '\n';
			int l = table.qry(rev[j-size], rev[j+1]);
			bool left = dp[i-1][j-size + size/2];
			bool right = dp[i-1][j+1+size/2];
			int leftMask = mask[i-1][j-size + size/2];
			int rightMask = mask[i-1][j+1+size/2];
			//std::cout << "l is " << l << '\n';
			if(l >= size) {
				assert(leftMask == rightMask && left == right);
				long long got = 0;
				if(left && (leftMask & (1 << (str[j] - 'a'))) == 0) {
					mask[i][j] = leftMask | (1 << (str[j] - 'a'));
					dp[i][j] = true;
					tot += f(size + size + 1);
					got += f(size + size + 1);
					sum[j - size] += f(size + size + 1);
					sum[j] -= f(size + size + 1);
					sum[j + 1] += f(size + size + 1);
					sum[j + size + 1] -= f(size + size + 1);
				}
				long long got2 = f(size + size + 1) - got;
				for(int x = 0; x < 26; x++) {
					if((leftMask & (1 << x)) != 0 || !left) {
						cost[j][x] += -got;
					} else {
						cost[j][x] += got2;
					}
				}
			} else {
				int l2 = l == size - 1 ? 0 : table.qry(rev[j-size+l+1], rev[j+2+l]);
				if(l2 + l >= size - 1) {
					if(left && (leftMask & (1 << (str[j] - 'a'))) == 0) {
						cost[j+l+1][str[j-size+l]-'a'] += f(size + size + 1);
					}
					if(right && (rightMask & (1 << (str[j] - 'a'))) == 0) {
						cost[j-size+l][str[j+l+1]-'a'] += f(size + size + 1);
					}
				}
			}
		}
		size = 2 * size + 1;
	}
	long long ans = tot;
	for(int i = 0; i < n; i++) {
		if(i) {
			sum[i] += sum[i-1];
		}
		for(int j = 0; j < 26; j++) {
			ans = std::max(ans, tot + cost[i][j] - sum[i]);
		}
	}
	std::cout << ans << '\n';
}