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

const int N = 200200;
int n, k;
ll a[N];
ll m;

void solve() {
	scanf("%d%lld%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	int g = 0;
	ll curCost = 0;
	while(k * (g + 1) - 1 < n && curCost + a[k * (g + 1) - 1] <= m) {
		curCost += a[k * (g + 1) - 1];
		g++;
	}
	curCost = 0;
	int ans = g * k;
	for (int p = 0; p < k && p + k * g < n; p++) {
		curCost += a[p];
		ll cur = curCost;
		for (int i = 1; i <= g; i++) {
			cur += a[p + i * k];
		}
		if (cur <= m) ans = g * k + p + 1;
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