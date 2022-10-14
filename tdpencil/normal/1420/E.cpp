#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
inline void umin(T &a, const T &b) {
	a = min(a, b);
}

template<typename T>
inline void umax(T &a, const T &b) {
	a = max(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	a.push_back(1);
	
	vector<int> gg;
	for (int i = 0; i <= n; ++i) {
		int s = i;
		while (a[i] == 0) ++i;
		gg.push_back(i - s);
	}
	
	vector<int> p = gg;
	partial_sum(begin(p), end(p), begin(p));
	
	constexpr int mx = 103;
	constexpr int dx = mx + 1, dy = mx + 1, dz = mx * (mx + 1) / 2 + 1;
	static int dp[dx][dy][dz] = {};
	
	for (int i = 0; i < dx; ++i) {
		for (int j = 0; j < dy; ++j) {
			for (int k = 0; k < dz; ++k) {
				dp[i][j][k] = INT_MAX;
			}
		}
	}
	dp[0][0][0] = 0;
	
	int k = gg.size(), l = p.back();
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= l; ++j) {
			for (int s = 0; s <= n * (n-1) / 2; ++s) {
				if (dp[i][j][s] == INT_MAX) continue;
				for (int q = j; q <= l; ++q) {
					umin(dp[i+1][q][s + abs(q - p[i])], dp[i][j][s] + (q-j)*(q-j));
				}
			}
		}
	}
	
	int mn = INT_MAX;
	for (int s = 0; s <= n * (n-1) / 2; ++s) {
		umin(mn, dp[k][l][s]);
		int val = l*l - mn;
		assert(val % 2 == 0);
		cout << val/2 << " ";
	}
	cout << endl;
	
	return 0;
}