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

#define y1 jhtdrs
#define y2 jnhtdrseadw

const int N = 222;
int n, m;
char s[N][N];
int x1, x2, y1, y2;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	x1 = n;
	x2 = 0;
	y1 = m;
	y2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'W') continue;
			x1 = min(x1, i);
			x2 = max(x2, i);
			y1 = min(y1, j);
			y2 = max(y2, j);
		}
	printf("%d %d\n", 1 + (x1 + x2) / 2, 1 + (y1 + y2) / 2);

	return 0;
}