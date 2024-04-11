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

const int K = 18;
const int N = (1 << K) + 5;
int par[N];
int sz[N];
int a[N];
int m = 1;
ll ans = 0;

int getPar(int v) {
	return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

ll tryUnite(int x, int y) {
	if (a[x] == 0 || a[y] == 0) return 0;
	if (a[x] > 0 && a[y] > 0) {
		return (ll)unite(a[x], a[y]);
	}
	int res = max(0, -a[x]) + max(0, -a[y]);
	int v = a[x];
	if (v < 0) v = a[y];
	if (v < 0) {
		v = m++;
		res--;
		par[v] = -1;
		sz[v] = 1;
	}
	a[x] = a[y] = v;
	return res;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		ans -= x;
		a[x]--;
	}
	a[0]--;

	for (int c = (1 << K) - 1; c > 0; c--) {
		for (int x = c; x > 0; x = (x - 1) & c) {
			int y = c ^ x;
			if (y >= x) break;
			ans += (ll)c * tryUnite(x, y);
		}
	}
	printf("%lld\n", ans);

	return 0;
}