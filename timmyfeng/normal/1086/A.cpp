#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

bool used[N][N];
bool best[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int>> points(3);
	for (auto& [x, y] : points) {
		cin >> x >> y;
	}

	int x, y, cnt;

	auto update_x = [&](int a) {
		while (x != a) {
			if (x > a) {
				--x;
			} else {
				++x;
			}
			if (!used[x][y]) {
				used[x][y] = true;
				++cnt;
			}
		}
	};

	auto update_y = [&](int a) {
		while (y != a) {
			if (y > a) {
				--y;
			} else {
				++y;
			}
			if (!used[x][y]) {
				used[x][y] = true;
				++cnt;
			}
		}
	};

	int ans = 1e9;
	vector<int> perm = {0, 1, 2};
	do {
		for (int dir1 = 0; dir1 < 2; ++dir1) {
			for (int dir2 = 0; dir2 < 2; ++dir2) {
				memset(used, false, sizeof used);
				x = points[perm[0]].first;
				y = points[perm[0]].second;
				used[x][y] = true;
				cnt = 1;

				if (dir1 == 0) {
					update_x(points[perm[1]].first);
					update_y(points[perm[1]].second);
				} else {
					update_y(points[perm[1]].second);
					update_x(points[perm[1]].first);
				}

				if (dir2 == 0) {
					update_x(points[perm[2]].first);
					update_y(points[perm[2]].second);
				} else {
					update_y(points[perm[2]].second);
					update_x(points[perm[2]].first);
				}

				if (cnt < ans) {
					ans = cnt;
					memcpy(best, used, sizeof used);
				}
			}
		}
	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans << "\n";
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			if (best[i][j]) {
				cout << i << " " << j << "\n";
			}
		}
	}
}