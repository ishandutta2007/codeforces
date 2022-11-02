#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 85;
int n, l[N], r[N];
double current[N], before[N], ans[N][N], dp[N][N];

int main() {
	vector<int> pos;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", l + i, r + i);
		pos.push_back(l[i]);
		pos.push_back(r[i]);
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	vector<pair<int, int> > block;
	for (int i = 0; i + 1 < (int)pos.size(); ++i) {
		block.push_back(make_pair(pos[i], pos[i + 1]));
	}
	for (int i = 0; i < (int)block.size(); ++i) {
		int ll = block[i].first, rr = block[i].second;
		vector<int> use;
		int frt = 0;
		for (int j = 0; j < n; ++j) {
			if (rr <= l[j] || r[j] <= ll) {
				current[j] = 0;
				if (r[j] <= ll) {
					++frt;
				}
			} else {
				current[j] = (double)(rr - ll) / (r[j] - l[j]);
				use.push_back(j);
			}
		}
		int m = use.size();
		for (int _ = 0; _ < m; ++_) {
			int j = use[_];
			for (int k = 0; k < m; ++k) {
				for (int u = 0; u < m; ++u) {
					dp[k][u] = 0;
				}
			}
			dp[0][0] = 1;
			for (int __ = 0; __ < m; ++__) {
				int k = use[__];
				if (k == j) {
					continue;
				}
				for (int u = __; u >= 0; --u) {
					for (int v = __; v >= 0; --v) {
						dp[u + 1][v] += dp[u][v] * before[k];
						dp[u][v + 1] += dp[u][v] * current[k];		
						dp[u][v] = dp[u][v] * (1 - before[k] - current[k]);
					}
				}
			}
			for (int u = m - 1; u >= 0; --u) {
				for (int v = m - 1; v >= 0; --v) {
					double p = dp[u][v] * current[j] / (1 + v);
					ans[j][frt + u] += p;
					ans[j][frt + u + v + 1] -= p;
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			before[j] += current[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j) {
				ans[i][j] += ans[i][j - 1];
			}
			printf("%.12f%c", ans[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}