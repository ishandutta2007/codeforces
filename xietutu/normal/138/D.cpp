#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
int n,m,M,minx,miny,maxx,maxy;
char s[25][25],a[45][45];
int f[55][55][55][55];
int solve(int x1, int y1, int x2, int y2) {
	if (x2 < x1 || y2 < y1) return 0;
	if (x1 < minx || x1 > maxx || y1 < miny || y1 > maxy ||
		x2 < minx || x2 > maxx || y2 < miny || y2 > maxy) return 0;  
	if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
	bool bo = false;
	for (int i = x1; i <= x2; ++i)
		for (int j = y1; j <= y2; ++j)
			if (a[i][j] == 'L' || a[i][j] == 'R' || a[i][j] == 'X') bo = true;
	if (!bo) return f[x1][y1][x2][y2] = 0;
	
	
	set<int> T;
	for (int i = x1; i <= x2; ++i)
		for (int j = y1; j <= y2; ++j) {
			if (a[i][j] == 'L') 
				T.insert(solve(x1, y1, x2, j - 1) ^ solve(x1, j + 1, x2, y2));
			if (a[i][j] == 'R') 
				T.insert(solve(x1, y1, i - 1, y2) ^ solve(i + 1, y1, x2, y2));
			if (a[i][j] == 'X')
				T.insert(solve(x1, y1, i - 1, j - 1) ^ solve(x1, j + 1, i - 1, y2) ^
					solve(i + 1, y1, x2, j - 1) ^ solve(i + 1, j + 1, x2, y2));
		}
	
	int s = 0;
	while (T.count(s)) ++s;
	return f[x1][y1][x2][y2] = s;
}
int main() {
	//freopen("138D.in","r",stdin);
	scanf("%d%d", &n, &m);
	for (int i = n; i >= 1; --i) 
		scanf("%s", s[i] + 1);
	M = 100;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			int t = i - j;
			if ((i + j) % 2 != 0) t = (t - 1) / 2;
			else t = t / 2;
			M = min(t, M);
		}
	
	M = -M;
	minx = 100, miny = 100, maxx = 0, maxy = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if ((i + j) % 2 == 0) {
				int X = (i + j) / 2, Y = (i - j) / 2 + M;
				minx = min(minx, X);
				miny = min(miny, Y);
				maxx = max(maxx, X);
				maxy = max(maxy, Y);
			 	a[X][Y] = s[i][j];
			 }
	memset(f ,255, sizeof(f));
	int s1 = solve(minx, miny, maxx, maxy);
	
	memset(a, 0, sizeof(a));
	minx = 100, miny = 100, maxx = 0, maxy = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if ((i + j) % 2 != 0) {
				int X = (i + j) / 2, Y = (i - j - 1) / 2 + M;
				minx = min(minx, X);
				miny = min(miny, Y);
				maxx = max(maxx, X);
				maxy = max(maxy, Y);
			 	a[X][Y] = s[i][j];
			 }
	memset(f ,255, sizeof(f));
	int s2 = solve(minx, miny, maxx, maxy);
	if (s1 ^ s2) printf("WIN\n");
	else printf("LOSE\n");
}