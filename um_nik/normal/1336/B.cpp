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

const ll INF = (ll)4e18;
ll ans;
vector<ll> a[3];
int p[3];

ll sqr(ll x) {
	return x * x;
}

void solve2() {
	int t1 = 0, t2 = 0;
	for (ll x : a[p[0]]) {
		while(t1 + 1 < (int)a[p[1]].size() && a[p[1]][t1 + 1] <= x) t1++;
		while(t2 + 1 < (int)a[p[2]].size() && a[p[2]][t2] < x) t2++;
		ll y = a[p[1]][t1], z = a[p[2]][t2];
		ans = min(ans, sqr(x - y) + sqr(x - z) + sqr(y - z));
	}
}

void solve() {
	ans = INF;
	for (int i = 0; i < 3; i++)
		a[i].clear();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	ll x;
	while(n--) {
		scanf("%lld", &x);
		a[0].push_back(x);
	}
	while(m--) {
		scanf("%lld", &x);
		a[1].push_back(x);
	}
	while(k--) {
		scanf("%lld", &x);
		a[2].push_back(x);
	}
	for (int i = 0; i < 3; i++)
		sort(all(a[i]));
	for (int i = 0; i < 3; i++)
		p[i] = i;
	do {
		solve2();
	} while(next_permutation(p, p + 3));
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