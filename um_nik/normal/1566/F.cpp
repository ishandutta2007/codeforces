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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const ll INF = (ll)1e17;
const int N = 200200;
set<ll> setik;
map<ll, ll> mapchik;
int n, m;
pll ord[N];
ll a[N];
pll b[N];
ll dp1[N][2];
ll dp2[N];

void read() {
	scanf("%d%d", &n, &m);
	setik.clear();
	mapchik.clear();
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		setik.insert(x);
	}
	for (int i = 0; i < m; i++) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ord[i] = mp(r - l, l);
	}
	sort(ord, ord + m);
	for (int i = 0; i < m; i++) {
		ll l = ord[i].second;
		ll r = l + ord[i].first;
		auto it2 = setik.lower_bound(l);
		if (it2 != setik.end() && *it2 <= r) continue;
		auto it = mapchik.lower_bound(l);
		if (it == mapchik.end() || it->second > r)
			mapchik[l] = r;
	}
	n = 0;
	for (ll x : setik) a[n++] = x;
	m = 0;
	for (pll t : mapchik) b[m++] = t;
	for (int i = 0; i < n; i++)
		dp1[i][0] = dp1[i][1] = INF;
	for (int i = 0; i <= m; i++)
		dp2[i] = INF;
	dp2[0] = 0;
}

void solve() {
	read();
	int p = 0, q = 0;
	while(p < n) {
		if (q == m || a[p] < b[q].first) {
			dp1[p][0] = min(dp1[p][0], dp2[q]);
			dp1[p][1] = min(dp1[p][1], dp2[q]);
			dp2[q] = min(dp2[q], dp1[p][0]);
			for (int i = q; i < m && (p == n - 1 || a[p + 1] > b[i].first); i++) {
				ll len = b[i].first - a[p];
				for (int j = 0; j < 2; j++)
					dp2[i + 1] = min(dp2[i + 1], dp1[p][j] + (2 - j) * len);
			}
			p++;
		} else {
			ll len = a[p] - b[q].second;
			for (int j = 0; j < 2; j++)
				dp1[p][j] = min(dp1[p][j], dp2[q] + len * (1 + j));
			q++;
		}
	}
	printf("%lld\n", dp2[m]);
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