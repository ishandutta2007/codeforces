#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const int modn = 1000000007;
inline int mod(int x) { return x % modn; }
char g[500][500];
int n, m;

inline bool inside(int i3, int j3, int i1, int j1, int i2, int j2) {
	return i3 >= i1 && i3 <= i2 && j3 >= j1 && j3 <= j2;
}

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int memo[2][500][500];

int main() {
	int i, j, i2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf(" %c", &g[i][j]);
	for(i = n - 1; i >= 0; i--)
		for(j = m - 1; j >= 0; j--)
			for(i2 = i; i2 < n; i2++) {
				int j2 = (m + n - 2 - i - j - i2);
				int &r = memo[i%2][j][i2]; r = 0;
				if(i > i2 || j > j2) { r = 0; continue; }
				if(g[i][j] != g[i2][j2]) { r = 0; continue; }
				if(i == i2 && j == j2) { r = 1; continue; }
				if(i == i2 && abs(j - j2) == 1) { r = g[i][j] == g[i2][j2]; continue; }
				if(j == j2 && abs(i - i2) == 1) { r = g[i][j] == g[i2][j2]; continue; }
				for(int d1 = 0; d1 <= 1; d1++)
					for(int d2 = 2; d2 <= 3; d2++) {
						int ni = i + dir[d1][0], nj = j + dir[d1][1];
						int ni2 = i2 + dir[d2][0], nj2 = j2 + dir[d2][1];
						if(!inside(ni, nj, i, j, i2, j2) || !inside(ni2, nj2, i, j, i2, j2)) continue;
						r = mod(r + memo[ni%2][nj][ni2]);
					}
			}
	printf("%d\n", memo[0][0][n-1]);
	return 0;
}