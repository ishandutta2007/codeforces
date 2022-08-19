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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5555;
int n, m, k;
int a[N];
int b[N];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m--;
	k = min(k, m);
	for (int i = 0; i <= m; i++)
		b[i] = max(a[i], a[n - 1 - m + i]);
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int cur = (int)1e9 + 7;
		for (int j = 0; j <= m - k; j++)
			cur = min(cur, b[i + j]);
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}