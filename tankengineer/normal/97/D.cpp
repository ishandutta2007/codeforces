#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;

const int N = 155, K = 100005;
int n, m, ex, ey;
char map[N][N], op[K];
bitset<150> st[150], tmp[150], stableUp[150], stableDown[150], stableLeft[150], stableRight[150];

void goup() {
	for (int i = 0; i < n; ++i) {
		tmp[i] = st[i] & stableUp[i];
		st[i]  ^= tmp[i];
	}
	for (int i = 0; i + 1 < n; ++i) {
		st[i] = st[i + 1];
	}
	st[n - 1].reset();
	for (int i = 0; i < n; ++i) {
		st[i] |= tmp[i];
	}
}

void godown() {
	for (int i = 0; i < n; ++i) {
		tmp[i] = st[i] & stableDown[i];
		st[i] ^= tmp[i];
	}
	for (int i = n - 1; i > 0; --i) {
		st[i] = st[i - 1];
	}
	st[0].reset();
	for (int i = 0; i < n; ++i) {
		st[i] |= tmp[i];
	}
}

void goleft() {
	for (int i = 0; i < n; ++i) {
		tmp[i] = st[i] & stableLeft[i];
		st[i] ^= tmp[i];
	}
	for (int i = 0; i < n; ++i) {
		(st[i] >>= 1) |= tmp[i];
	}
}

void goright() {
	for (int i = 0; i < n; ++i) {
		tmp[i] = st[i] & stableRight[i];
		st[i] ^= tmp[i];
	}
	for (int i = 0; i < n; ++i) {
		(st[i] <<= 1) |= tmp[i];
	}
}

void initst() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] != '#') {
				st[i].set(j);
			}
		}
	}
}

void initUDLR() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '#') {
				continue;
			}
			if (i == 0 || map[i - 1][j] == '#') {
				stableUp[i].set(j);
			}
			if (i == n - 1 || map[i + 1][j] == '#') {
				stableDown[i].set(j);
			}
			if (j == 0 || map[i][j - 1] == '#') {
				stableLeft[i].set(j);
			}
			if (j == m - 1 || map[i][j + 1] == '#') {
				stableRight[i].set(j);
			}
		}
	}
}

bool check() {
	int k = st[ex][ey];
	st[ex].reset(ey);
	for (int i = 0; i < n; ++i) {
		if (st[i].any()) {
			st[ex][ey] = k;
			return false;
		}
	}
	return true;
}

int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	int cntone = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		for (int j = 0; j < m; ++j) {
			cntone += map[i][j] != '#';
			if (map[i][j] == 'E') {
				ex = i;
				ey = j;
			}
		}
	}
	if (cntone == 1) {
		printf("0\n");
		return 0;
	}
	initst();
	initUDLR();
	scanf("%s", op);
	for (int i = 0; i < k; ++i) {
		if (op[i] == 'U') {
			goup();
		}
		if (op[i] == 'D') {
			godown();
		}
		if (op[i] == 'L') {
			goleft();
		}
		if (op[i] == 'R') {
			goright();
		}
		if (check()) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}