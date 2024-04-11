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

const int N = 300300;
int a[N];
ll ans;
int n;

void add(int p, ll x) {
	x *= a[p];
	if (a[p] > a[p - 1] && a[p] > a[p + 1])
		ans += x;
	if (a[p] < a[p - 1] && a[p] < a[p + 1])
		ans -= x;
}

void solve() {
	ans = 0;
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		add(i, 1);
	printf("%lld\n", ans);
	while(q--) {
		int v, u;
		scanf("%d%d", &v, &u);
		set<int> toChange;
		for (int i = -1; i <= 1; i++) {
			if (v + i > 0 && v + i <= n) toChange.insert(v + i);
			if (u + i > 0 && u + i <= n) toChange.insert(u + i);
		}
		for (int p : toChange)
			add(p, -1);
		swap(a[v], a[u]);
		for (int p : toChange)
			add(p, 1);
		printf("%lld\n", ans);
	}
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