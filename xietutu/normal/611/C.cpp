#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;
int h, w, q;
char s[505];
int a[505][505], r[505][505], c[505][505], cntr[505][505], cntc[505][505];
int main() {
	scanf("%d%d", &h, &w); 
	for (int i = 1; i <= h; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= w; ++j)
			if (s[j] == '.') a[i][j] = 1;
			else a[i][j] = 0;
	}
	
	for (int i = 1; i <= h; ++i) 
		for (int j = 1; j <= w; ++j) {
			r[i][j] = r[i][j - 1];
			cntr[i][j] = cntr[i][j - 1];
			if (a[i][j] == 1 && a[i][j - 1] == 0) ++r[i][j];
			if (a[i][j] == 1) ++cntr[i][j];
		}
	
	for (int j = 1; j <= w; ++j) 
		for (int i = 1; i <= h; ++i) {
			c[i][j] = c[i - 1][j];
			cntc[i][j] = cntc[i - 1][j];
			if (a[i][j] == 1 && a[i - 1][j] == 0) ++c[i][j];
			if (a[i][j] == 1) ++cntc[i][j];
		}
	
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int ans = 0;
		for (int i = r1; i <= r2; ++i) {
			ans += cntr[i][c2] - cntr[i][c1 - 1];
			int len = r[i][c2] - r[i][c1 - 1];
			if (a[i][c1] == 1 && a[i][c1 - 1] == 1) ++len;
			ans -= len;
		}
		
		for (int j = c1; j <= c2; ++j) {
			ans += cntc[r2][j] - cntc[r1 - 1][j];
			int len = c[r2][j] - c[r1 - 1][j];
			if (a[r1][j] == 1 && a[r1 - 1][j] == 1) ++len;
			ans -= len;
		}
		printf("%d\n", ans);
	}
}