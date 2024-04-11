//#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

const int MAX_N = 60;
char field[MAX_N][MAX_N];
int perm[4];
bool uses[4];
int cnt = 0;
int sx, sy, ex, ey, n, m;
string way;

bool check() {
	int x = sx, y = sy;
	int now;
	for (int i = 0; i < way.length(); i++) {
		now = perm[way[i] - '0'];
		if (now == 0) {
			x++;
		}
		if (now == 1) {
			y++;
		}
		if (now == 2) {
			x--;
		}
		if (now == 3) {
			y--;
		}
		if (x < 0 || y < 0 || x == n || y == m) {
			return 0;
		}
		if (field[x][y] == '#') return 0;
		if (x == ex && y == ey) return 1;
	}
	return 0;
}

void gen(int nn) {
	if (nn == 4) {
		if (check()) cnt++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (uses[i]) {
			perm[nn] = i;
			uses[i] = 0;
			gen(nn + 1);
			uses[i] = 1;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		uses[i] = 1;
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (field[i][j] == 'E') {
				ex = i;
				ey = j;
			}
		}
	}
	cin >> way;
	gen(0);
	cout << cnt << endl;
	return 0;
}