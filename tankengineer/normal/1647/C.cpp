#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 105;

int n, m;

char map[N][N], cur[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", map[i]);
		}
		if (map[0][0] == '1') {
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cur[i][j] = '0';
			}
		}
		vector<pair<pair<int, int>, pair<int, int> > > ans;
		for (int i = 0; i < n; ++i) {
			for (int j = m - 1; j > 0; --j) {
				if (map[i][j] == '1') {
					ans.push_back(make_pair(make_pair(i, j - 1), make_pair(i, j)));
					cur[i][j] = '1';
				}
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			if (map[i][0] == '1') {
				ans.push_back(make_pair(make_pair(i - 1, 0), make_pair(i, 0)));
				cur[i][0] = '1';
			}
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) {
			printf("%d %d %d %d\n", ans[i].first.first + 1,
				                    ans[i].first.second + 1,
									ans[i].second.first + 1,
									ans[i].second.second + 1);
		}
	}
	return 0;
}