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

const ll MOD = 998244353;

const int N = 200200;
ll a[N];
ll pref[N];
int fenv[2][N];
ll xs[N];
int xsSz;

int solveSmall(int n) {
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<int> cd, pd;
		int lastC = -1, lastP = -1;
		ll bal = 0;
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				bal += a[i];
				if (lastP != -1) pd.push_back(i - lastP);
				lastP = i;
			} else {
				bal -= a[i];
				if (lastC != -1) cd.push_back(i - lastC);
				lastC = i;
			}
		}
		bool ok = bal > 0;
		for (int i = 1; i < (int)cd.size(); i++)
			ok &= cd[i] >= cd[i - 1];
		for (int i = 1; i < (int)pd.size(); i++)
			ok &= pd[i] <= pd[i - 1];
		if (ok) {
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) {
					eprintf("p");
				} else {
					eprintf("c");
				}
			}
			eprintf("\n");
			ans++;
		}
	}
	return ans;
}

void addFenv(int k, int p, int dx) {
	for(; p < N; p |= p + 1)
		fenv[k][p] += dx;
}
int getFenv(int k, int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[k][r];
	return res;
}

ll solve(vector<ll> b, ll S) {
	eprintf("solve S = %lld\n", S);
	for (ll x : b)
		eprintf("%lld ", x);
	eprintf("\n");
	int n = (int)b.size();
	for (int i = 0; i <= n; i++)
		fenv[0][i] = fenv[1][i] = 0;
	pref[0] = pref[1] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 2] = pref[i] + 2 * b[i];
	xsSz = 0;
	for (int i = 0; i <= n + 1; i++)
		xs[xsSz++] = pref[i];
	sort(xs, xs + xsSz);
	xsSz = unique(xs, xs + xsSz) - xs;
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		int p = lower_bound(xs, xs + xsSz, pref[i]) - xs;
		addFenv(i & 1, p, 1);
		p = lower_bound(xs, xs + xsSz, S - pref[i + 1]) - xs;
		ans += getFenv(i & 1, p - 1);
	}
	eprintf("ans = %lld\n", ans);
	return ans;
}

void solve() {
	int n;
	scanf("%d", &n);
	ll S = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		S += a[i];
	}
	if (n <= 6) {
		printf("%d\n", solveSmall(n));
		return;
	}
	ll ans = 0;
	ll bal = 0;
	for (int i = n - 1; i >= 0; i--) {
		bal += 2 * a[i];
		if (bal < S && i <= n - 2 && i >= 2) ans++;
	}
	for (int mask = 0; mask < 4; mask++) {
		int l = 0, r = n;
		ll curS = S;
		if (mask & 1) {
			curS -= 2 * (a[1] + a[2]);
			l = 3;
		}
		if (mask & 2) {
			curS -= 2 * a[n - 1];
			r = n - 3;
		}
		vector<ll> b = vector<ll>(a + l, a + r);
		ans += solve(b, curS);
	}
//	eprintf("%d\n", solveSmall(n));
	printf("%lld\n", ans % MOD);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}

	return 0;
}