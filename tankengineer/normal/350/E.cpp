#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 300;
int n, m, k, a[N];
bool g[N][N], use[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", a + i);
		--a[i];
		use[a[i]] = true;
	}
	int cnt = k;
	for (int i = 0; i < n; ++i) {
		if (!use[i]) {
			a[cnt++] = i;
		}
	}
	if (k == n || m > n * (n - 1) / 2 - (k - 1)) {
		printf("-1\n");
		return 0;
	} else {
		for (int i = 0; i < n; ++i) {
			g[i][i] = true;
		}
		for (int i = 1; i < k; ++i) {
			g[i][0] = g[0][i] = true;
		}
		int p = 0;
		vector<pair<int, int> > ans;		
		ans.push_back(make_pair(k, 0));
		ans.push_back(make_pair(k, 1));
		for (int i = 1; i < k - 1; ++i) {
			ans.push_back(make_pair(i, i + 1));
		}
		for (int i = k; i < n - 1; ++i) {
			ans.push_back(make_pair(i, i + 1));
		}
		for (int i = 0; i < (int)ans.size(); ++i) {
			g[ans[i].first][ans[i].second] = true;
			g[ans[i].second][ans[i].first] = true;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (ans.size() < m && !g[i][j]) {
					ans.push_back(make_pair(i, j));
					g[i][j] = g[j][i] = true;
				}
			}
		}
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d %d\n", a[ans[i].first] + 1, a[ans[i].second] + 1);
		}
	}
	return 0;
}