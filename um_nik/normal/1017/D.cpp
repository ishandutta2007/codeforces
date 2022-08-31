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

const int N = (1 << 12) + 7;
const int M = 101;
const int K = 15;
int w[K];
int a[N];
int b[N][M];
int c[N];
int n, m, q;
char s[K];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int mask = 0; mask < (1 << n); mask++) {
		c[mask] = 0;
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 0)
				c[mask] += w[i];
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		int mask = 0;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				mask ^= 1 << j;
		a[mask]++;
	}
	for (int m1 = 0; m1 < (1 << n); m1++)
		for (int m2 = 0; m2 < (1 << n); m2++) {
			if (c[m1 ^ m2] < M)
				b[m1][c[m1 ^ m2]] += a[m2];
		}
	while(q--) {
		int k;
		scanf("%s %d", s, &k);
		int mask = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				mask ^= 1 << i;
		int ans = 0;
		for (int i = 0; i <= k; i++)
			ans += b[mask][i];
		printf("%d\n", ans);
	}

	return 0;
}