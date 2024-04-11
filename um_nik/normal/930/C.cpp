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

const int INF = 1001010;
const int N = 100100;
int n, m;
int a[N];
int b[2][N];
int c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	while(m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		a[l]++;
		a[r]--;
	}
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];

	for (int i = 0; i <= n + 1; i++)
		c[i] = INF;
	c[0] = 0;
	int pos = 0;
	b[0][0] = pos;
	for (int i = 0; i < n; i++) {
		int x = upper_bound(c, c + n + 1, a[i]) - c;
		c[x] = a[i];
		while(c[pos + 1] < INF) pos++;
		b[0][i + 1] = pos;
	}
	for (int i = 0; i <= n + 1; i++)
		c[i] = INF;
	c[0] = 0;
	pos = 0;
	b[1][n] = pos;
	for (int i = n - 1; i >= 0; i--) {
		int x = upper_bound(c, c + n + 1, a[i]) - c;
		c[x] = a[i];
		while(c[pos + 1] < INF) pos++;
		b[1][i] = pos;
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, b[0][i] + b[1][i]);
	printf("%d\n", ans);

	return 0;
}