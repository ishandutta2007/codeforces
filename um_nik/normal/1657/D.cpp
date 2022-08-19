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

const int N = (int)1e6 + 77;
const ll INF = (ll)2e18;
ll a[N];
ll b[N];
int n, m;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(n--) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		b[x] = max(b[x], y * z);
	}
	for (int i = 1; i <= m; i++) if (b[i] > 0)
		for (int j = 1; i * j <= m; j++)
			a[i * j] = max(a[i * j], b[i] * j);
	for (int i = 1; i <= m; i++)
		a[i] = max(a[i], a[i - 1]);
	scanf("%d", &n);
	while(n--) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		x *= y;
		int p = upper_bound(a, a + m + 1, x) - a;
		if (p <= m)
			printf("%d\n", p);
		else
			printf("-1\n");
	}

	return 0;
}