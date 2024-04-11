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

const ll INF = (ll)1e18;
const int LOG = 20;
const int N = (int)1e6 + 77;
int n, m;
ll ans[N];
ll toAdd = 0;
int sparse[LOG][N];
int p2[N];
int k;

ll getMax(int l, int r) {
	if (r <= l) return -INF;
	int j = p2[r - l];
	return max(sparse[j][l], sparse[j][r - (1 << j)]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%d%d", &n, &m);
	while(n--) {
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &sparse[0][i]);
		for (int j = 0; j < LOG - 1; j++)
			for (int i = 0; i + (1 << (j + 1)) <= k; i++)
				sparse[j + 1][i] = max(sparse[j][i], sparse[j][i + (1 << j)]);
		ll w = max(0LL, getMax(0, k));
		toAdd += w;
		for (int i = 0; i <= k + 1; i++) {
			if (i >= m) continue;
			int r = i, l = i - (m - k);
			ll x = -INF;
			if (r >= k) {
				x = 0;
				r = k - 1;
			}
			if (l < 0) {
				x = 0;
				l = 0;
			}
			x = max(x, getMax(l, r + 1));
			ans[i] += x - w;
		}
		for (int i = m - 1; i >= m - k - 2; i--) {
			if (i <= k + 1) continue;
			int r = i, l = i - (m - k);
			ll x = -INF;
			if (r >= k) {
				x = 0;
				r = k - 1;
			}
			if (l < 0) {
				x = 0;
				l = 0;
			}
			x = max(x, getMax(l, r + 1));
			ans[i] += x - w;
		}
	}
	for (int i = 0; i < m; i++)
		printf("%lld ", toAdd + ans[i]);
	printf("\n");

	return 0;
}