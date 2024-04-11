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

const int LOG = 20;
const int N = (int)2e7 + 33;
const int M = (int)1e6 + 3;
int p[M];
bool used[N];
int n, m;
int a[LOG];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int k = 1; k < LOG; k++) {
		a[k] = a[k - 1];
		for (int x = 1; x <= m; x++) {
			if (!used[k * x]) {
				used[k * x] = 1;
				a[k]++;
			}
		}
	}
	for (int x = 2; x < M; x++) {
		if (p[x]) continue;
		for (int y = x; y < M; y += x)
			if (p[y] == 0)
				p[y] = x;
	}
	ll ans = 1;
	for (int x = 2; x <= n; x++) {
		int g = 0;
		int y = x;
		while(y > 1) {
			int k = 0;
			int d = p[y];
			while(y % d == 0) {
				k++;
				y /= d;
			}
			g = gcd(g, k);
		}
		if (g != 1) continue;
		int k = 0;
		ll z = x;
		while(z <= n) {
			k++;
			z *= x;
		}
		ans += a[k];
	}
	printf("%lld\n", ans);

	return 0;
}