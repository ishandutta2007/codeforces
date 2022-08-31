#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 7;
const int N = 200200;
int a[N][4];
int b[N][4];
int c[N][4];
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &a[i][j]);

	c[n][0] = c[n][1] = b[0][0] = b[0][1] = -INF;
	c[n][2] = c[n][3] = b[0][2] = b[0][3] = INF;
	for (int i = 0; i < n; i++) {
		b[i + 1][0] = max(b[i][0], a[i][0]);
		b[i + 1][1] = max(b[i][1], a[i][1]);
		b[i + 1][2] = min(b[i][2], a[i][2]);
		b[i + 1][3] = min(b[i][3], a[i][3]);
	}
	for (int i = n - 1; i >= 0; i--) {
		c[i][0] = max(c[i + 1][0], a[i][0]);
		c[i][1] = max(c[i + 1][1], a[i][1]);
		c[i][2] = min(c[i + 1][2], a[i][2]);
		c[i][3] = min(c[i + 1][3], a[i][3]);
	}
	for (int i = 0; i < n; i++) {
		int x1 = max(b[i][0], c[i + 1][0]);
		int y1 = max(b[i][1], c[i + 1][1]);
		int x2 = min(b[i][2], c[i + 1][2]);
		int y2 = min(b[i][3], c[i + 1][3]);
		if (x1 <= x2 && y1 <= y2) {
			printf("%d %d\n", x1, y1);
			return 0;
		}
	}
	throw;

	return 0;
}