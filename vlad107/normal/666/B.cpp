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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 3022;
const long long INF = 1e9 + 19;
 
using namespace std;

int dst[N][N],n, m, q[N], qb, qe, d1[N], d2[N], d3[N], n1[N], n2[N], n3[N], ans, na, nb, nc, nd;
int d4[N], d5[N], d6[N], n4[N], n5[N], n6[N], dst2[N][N];
vector<int> g[N], gr[N];

void upd(int a, int b, int c, int d) {
	if ((a == c) || (a == d)) return;
	if ((d == b) || (d == a)) return;
	if ((a == b) || (c == d)) return;
	if ((dst[a][b] == -1) || (dst[b][c] == -1) || (dst[c][d] == -1)) return;
	int cur = dst[a][b] + dst[b][c] + dst[c][d];
	if (cur > ans) {
		ans = cur;
		na = a;
		nb = b;
		nc = c;
		nd = d;
	}
}

int main() {
	// freopen( "input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].pb(y);
		gr[y].pb(x);
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) dst[x][y] = -1;
		qb = -1, qe = 0;
		q[0] = x;
		dst[x][x] = 0;
		while (qb < qe) {
			int y = q[++qb];
			for (int i = 0; i < (int)g[y].size(); i++) {
				int z = g[y][i];
				if (dst[x][z] == -1) {
					dst[x][z] = dst[x][y] + 1;
					q[++qe] = z;
				}
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) dst2[x][y] = -1;
		qb = -1, qe = 0;
		q[0] = x;
		dst2[x][x] = 0;
		while (qb < qe) {
			int y = q[++qb];
			for (int i = 0; i < (int)gr[y].size(); i++) {
				int z = gr[y][i];
				if (dst2[x][z] == -1) {
					dst2[x][z] = dst2[x][y] + 1;
					q[++qe] = z;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		d1[i] = d2[i] = d3[i] = -1;
		for (int j = 0; j < n; j++) {
			if (dst[i][j] >= d1[i]) {
				d3[i] = d2[i]; d2[i] = d1[i];
				n3[i] = n2[i]; n2[i] = n1[i];
				d1[i] = dst[i][j];
				n1[i] = j;
			} else if (dst[i][j] >= d2[i]) {
				d3[i] = d2[i];
				n3[i] = n2[i];
				d2[i] = dst[i][j];
				n2[i] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		d4[i] = d5[i] = d6[i] = -1;
		for (int j = 0; j < n; j++) {
			if (dst2[i][j] >= d4[i]) {
				d6[i] = d5[i]; d5[i] = d4[i];
				n6[i] = n5[i]; n5[i] = n4[i];
				d4[i] = dst2[i][j];
				n4[i] = j;
			} else if (dst2[i][j] >= d5[i]) {
				d6[i] = d5[i];
				n6[i] = n5[i];
				d5[i] = dst2[i][j];
				n5[i] = j;
			}
		}
	}
	ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			upd(n4[i], i, j, n1[j]);
			upd(n4[i], i, j, n2[j]);
			upd(n4[i], i, j, n3[j]);
			upd(n5[i], i, j, n1[j]);
			upd(n5[i], i, j, n2[j]);
			upd(n5[i], i, j, n3[j]);
			upd(n6[i], i, j, n1[j]);
			upd(n6[i], i, j, n2[j]);
			upd(n6[i], i, j, n3[j]);
		}
	} 
	// cerr << ans << endl;
	// cerr << dst[na][nb] << endl;
	// cerr << dst[nb][nc] << endl;
	// cerr << dst[nc][nd] << endl;
	cout << na + 1 << " " << nb + 1 << " " << nc + 1 << " " << nd + 1 << endl;
}