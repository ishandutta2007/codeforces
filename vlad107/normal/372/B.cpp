#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define INF 1000000000

using namespace std;

int f[42][42][42][42], h[42][42][42][42], g[42][42][42][42], n, m, k, a[42][42], b[42][42];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x = getchar();
			a[i][j] = x - '0';
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
		}
		scanf("\n");
	}
	for (int x1 = 1; x1 <= n; x1++)
		for (int y1 = 1; y1 <= m; y1++)
			for (int x2 = x1; x2 <= n; x2++)
				for (int y2 = y1; y2 <= m; y2++)
					if (b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1] == 0)
						f[x1][y1][x2][y2] = 1;
					else
						f[x1][y1][x2][y2] = 0;
	for (int x1 = n; x1 >= 1; x1--)
		for (int y1 = m; y1 >= 1; y1--)
			for (int x2 = x1; x2 <= n; x2++)
				for (int y2 = y1; y2 <= m; y2++)
					g[x1][y1][x2][y2] = f[x1][y1][x2][y2] + g[x1 + 1][y1][x2][y2] + g[x1][y1 + 1][x2][y2] - g[x1 + 1][y1 + 1][x2][y2];
	for (int x1 = 1; x1 <= n; x1++)
		for (int y1 = 1; y1 <= m; y1++)
			for (int x2 = x1; x2 <= n; x2++)
				for (int y2 = y1; y2 <= m; y2++)
					h[x1][y1][x2][y2] = h[x1][y1][x2 - 1][y2] + h[x1][y1][x2][y2 - 1] - h[x1][y1][x2 - 1][y2 - 1] + g[x1][y1][x2][y2];
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", h[x1][y1][x2][y2]);
	}
}