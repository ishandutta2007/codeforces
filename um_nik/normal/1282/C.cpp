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
ll T;
ll A, B;
ll ans;
pll a[N];
int n;

void solve() {
	ans = 0;
	scanf("%d%lld%lld%lld", &n, &T, &A, &B);
	ll E = 0, H = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i].second);
		if (a[i].second == 0)
			E++;
		else
			H++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i].first);
	}
	sort(a, a + n);
	a[n] = mp(T + 1, -1);
	ll haveToSpend = 0;
	for (int i = 0; i <= n; i++) {
		if (haveToSpend <= a[i].first - 1) {
			ll hv = a[i].first - 1 - haveToSpend;
			if (E * A > hv) {
				ans = max(ans, i + hv / A);
			} else {
				ans = max(ans, i + E + min(H, (hv - A * E) / B));
			}
		}
		if (a[i].second == 0) {
			haveToSpend += A;
			E--;
		} else if (a[i].second == 1) {
			haveToSpend += B;
			H--;
		}
	}
	printf("%lld\n", ans);
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