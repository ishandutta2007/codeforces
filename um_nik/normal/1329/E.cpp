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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e15 + 66;
const int N = 400400;
ll a[N];
int n;
ll k;
pll b[N];
int m;

void read() {
	ll s;
	scanf("%lld%d%lld", &s, &n, &k);
	ll lst = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		a[i] = x - lst;
		lst = x;
	}
	a[n++] = s - lst;
}

ll calcMin(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += a[i] / x - 1;
	return res;
}
ll calcMax(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += (a[i] - 1) / x;
	return res;
}

void solve() {
	read();
	ll l = 1, r = INF;
	for (int i = 0; i < n; i++)
		r = min(r, a[i]);
	r++;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		ll z = calcMin(x);
		if (z < k)
			r = x;
		else
			l = x;
	}
	ll L = l;
	l = 0; r = INF;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		ll z = calcMax(x);
		if (z > k)
			l = x;
		else
			r = x;
	}
	ll R = r;
	assert(L <= R);
	m = 0;
	for (int i = 0; i < n; i++) {
		ll x = a[i] / L;
		ll y = (a[i] - 1) / R + 1;
		if (x >= y) continue;
		b[m++] = mp(a[i] / y, (a[i] - 1) / x + 1);
	}
	sort(b, b + m);
	ll ans = INF;
	b[m++] = mp(L, R);
	for (int i = 0; i < m; i++) {
		ans = min(ans, R - b[i].first);
		R = max(R, b[i].second);
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}