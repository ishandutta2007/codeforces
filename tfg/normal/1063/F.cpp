#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

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

int idx[ms];
int last[ms];
bool dp[2][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n;
	str = std::string(n, 'a');
	std::cin >> str;
	std::vector<char> wtf(str.begin(), str.end());
	SuffixArray<char> builder;
	std::vector<int> sa = builder.buildSuffix(wtf);
	std::vector<int> lcp = builder.buildLCP(sa, wtf);
	int ans = 1;
	for(int i = 0; i < n; i++) dp[1][i] = true;
	for(int i = 2; (i * (i + 1) / 2) <= n; i++) {
		//std::cout << "trying " << i << std::endl;
		int c = 0;
		for(int j = 0; j < n; j++) {
			idx[sa[j]] = c;
			if(lcp[j] < i - 1) {
				c++;
			}
		}
		for(int j = 0; j <= c; j++) {
			last[j] = -1;
		}
		//std::cout << "c is " << c << std::endl;
		for(int j = 0; j < n; j++) {
			dp[i&1][j] = false;
		}
		for(int j = n - 1; j >= 0; j--) {
			int lst = last[idx[j]];
			if(lst == -1) {
				if(dp[(i+1)&1][j]) {
					last[idx[j]] = j;
				}
				continue;
			}
			if(!dp[(i+1)&1][lst]) {
				continue;
			}
			if(lst - j >= i) {
				dp[i&1][j] = true;
			}
			if(j && lst - j >= i - 1) {
				dp[i&1][j-1] = true;
			}
		}
		bool valid = false;
		for(int j = 0; j < n; j++) {
			valid = valid || dp[i&1][j];
		}
		if(!valid) break;
		ans = i;
	}
	std::cout << ans << std::endl;
}