#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n, m, sumc[N][N], sumr[N][N];
char map[N][N];

int cal(int x, int y, int l) {
	if (l == 0) {
		return map[x][y] == 'w';
	}
	int ret = 0;
	ret += sumc[x][y + l + 1] - sumc[x][y];
	ret += sumc[x + l][y + l + 1] - sumc[x + l][y];
	ret += sumr[x + l][y] - sumr[x + 1][y];
	ret += sumr[x + l][y + l] - sumr[x + 1][y + l];
	return ret;
}

int cnt, ans, ansx, ansy;

void update(int x, int y, int l) {
	bool ret = cal(x, y, l) == cnt;
	if (ret && l < ans) {
		ans = l;
		ansx = x;
		ansy = y;
	}
}

void solve(int x, int y) {
	for (int l = 0; l < min(n, m); ++l) {
		if (x + l < n && y + l < m) {
			update(x, y, l);
		}
		if (x + l < n && y - l >= 0) {
			update(x, y - l, l);
		}
		if (x - l >= 0 && y + l < m) {
			update(x - l, y, l);
		}
		if (x - l >= 0 && y - l >= 0) {
			update(x - l, y - l, l);
		}
	}
}

int main() {
	vector<pair<int, int> > pos;
	cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'w') {
				pos.push_back(make_pair(i, j));
			}
			cnt += map[i][j] == 'w';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sumc[i][j + 1] = sumc[i][j] + (int)(map[i][j] == 'w');
			sumr[i + 1][j] = sumr[i][j] + (int)(map[i][j] == 'w');
		}
	}
	ans = 50005, ansx = -1, ansy = -1;
	for (int i = 0; i < n; ++i) {
		solve(i, pos[0].second);
	}
	for (int i = 0; i < m; ++i) {
		solve(pos[0].first, i);
	}
	if (ans == 50005) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i <= ans; ++i) {
		int l = ans;
		if (map[ansx][ansy + i] != 'w') {
			map[ansx][ansy + i] = '+';
		}
		if (map[ansx + i][ansy] != 'w') {
			map[ansx + i][ansy] = '+';
		}
		if (map[ansx + l][ansy + i] != 'w') {
			map[ansx + l][ansy + i] = '+';
		}
		if (map[ansx + i][ansy + l] != 'w') {
			map[ansx + i][ansy + l] = '+';
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", map[i]);
	}
	return 0;
}