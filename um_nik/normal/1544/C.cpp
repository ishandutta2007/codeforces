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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int INF = (int)1e7;
const int N = 100100;
ll a[N], b[N];
int n;

bool check(int m) {
	if (m < n) return false;
	int k = m / 4;
	ll S = 0;
	if (k <= n) {
		S += (ll)(m - n) * 100 + a[n] - a[k];
	} else {
		S += (ll)(m - k) * 100;
	}
	if (k <= m - n) {
		S -= b[n];
	} else {
		S -= b[n] - b[k - (m - n)];
	}
	return S >= 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	int ans = 4 * INF;
	for (int rm = 0; rm < 4; rm++) {
		int l = -1, r = INF;
		while(r - l > 1) {
			int x = (l + r) / 2;
			if (check(4 * x + rm))
				r = x;
			else
				l = x;
		}
		ans = min(ans, 4 * r + rm);
	}
	printf("%d\n", ans - n);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}