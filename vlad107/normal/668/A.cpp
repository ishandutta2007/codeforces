#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
 
using namespace std;

const int N = 111;

int n, m, q, cnt, nom[N][N], a[N * N];

void rotRow(int x) {
	int tmp = nom[x][0];
	for (int i = 0; i + 1 < m; i++) nom[x][i] = nom[x][i + 1];
	nom[x][m - 1] = tmp;
}

void rotCol(int y) {
	int tmp = nom[0][y];
	for (int i = 0; i + 1 < n; i++) nom[i][y] = nom[i + 1][y];
	nom[n - 1][y] = tmp;
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			nom[i][j] = cnt++;
		}
	}
	memset(a, -1, sizeof(a));
	for (int i = 0; i < q; i++) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x;
			scanf("%d", &x);
			--x;
			rotRow(x);
		} else if (tp == 2) {
			int x;
			scanf("%d", &x);
			--x;
			rotCol(x);
		} else if (tp == 3) {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			--x; --y;
			int t = nom[x][y];
//			cerr << t << endl;
			a[t] = v;
		} else assert(false);
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[cnt++]);
		}
		puts("");
	}
}