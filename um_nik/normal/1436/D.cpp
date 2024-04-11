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

const int N = 200200;
int n;
int par[N];
ll a[N];
ll sz[N];
ll ans = 0;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &par[i]);
		par[i]--;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sz[i] = 1;
	}
	for (int i = 1; i < n; i++)
		sz[par[i]] = 0;
	for (int i = n - 1; i > 0; i--) {
		a[par[i]] += a[i];
		sz[par[i]] += sz[i];
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, (a[i] + sz[i] - 1) / sz[i]);
	printf("%lld\n", ans);

	return 0;
}