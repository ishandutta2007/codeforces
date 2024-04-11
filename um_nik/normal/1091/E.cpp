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

const int N = 500500;
int n;
ll a[N];
ll pref[N];
ll b[N], c[N];
bool good[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];
	for (int k = 0; k <= n; k++) {
		int l = -1, r = n;
		while(r - l > 1) {
			int x = (l + r) / 2;
			if (a[x] <= k + 1)
				r = x;
			else
				l = x;
		}
		r = max(r, k);
		b[k] = (ll)k * (k + 1) + (pref[n] - pref[r] + (ll)(r - k) * (k + 1)) - pref[k];
		l = -1, r = n;
		while(r - l > 1) {
			int x = (l + r) / 2;
			if (a[x] <= k)
				r = x;
			else
				l = x;
		}
		r = max(r, k);
		c[k] = pref[k] - (pref[n] - pref[r] + (ll)(r - k) * k) - (ll)k * (k - 1);
	}
	for (int i = 0; i < n; i++)
		c[i + 1] = max(c[i], c[i + 1]);
	for (int i = n - 1; i >= 0; i--)
		b[i] = min(b[i], b[i + 1]);
	for (int k = 0; k <= n; k++) {
		ll l = c[k], r = b[k];
		if (k == 0)
			r = min(r, (ll)n);
		else
			r = min(r, a[k - 1]);
		if (k == n)
			l = max(l, 0LL);
		else
			l = max(l, a[k]);
		for (ll i = l; i <= r; i++)
			good[i] = 1;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum ^= (a[i] & 1);
	bool ok = false;
	for (int i = 0; i <= n; i++) {
		if (!good[i]) continue;
		if ((i & 1) != sum) continue;
		ok = true;
		printf("%d ", i);
	}
	if (!ok)
		printf("-1");
	printf("\n");

	return 0;
}