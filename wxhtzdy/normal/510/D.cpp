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
#include <iomanip>
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

const int N = 305;
int n;
int l[N];
int c[N];

int main()
{
	startTime = clock();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", l + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}
	int G = l[1];
	for (int  i = 1; i <= n; i++) {
		G = __gcd(G, l[i]);
	}
	if (G > 1) {
		printf("-1");
		return 0;
	}
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		vector<int> p;
		int x = l[i];
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				p.push_back(j);
				while (x % j == 0) {
					x /= j;
				}
			}
		}
		if (x > 1) {
			p.push_back(x);
		}
		sort(all(p));
		int m = p.size();
		for (int j = 0; j + 1 < m; j++) {
			assert(p[j] != p[j + 1]);
		}
		vector<int> b(n + 1);
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			for (int x = 0; x < m; x++) {
				if (l[j] % p[x] == 0) {
					b[j] |= (1 << x);
				}
			}
		}
		vector<int> dp(1 << m, 1e9);
		dp[(1 << m) - 1] = c[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int mask = 0; mask < (1 << m); mask++) {
				int nmask = (mask & b[j]);
				dp[nmask] = min(dp[nmask], dp[mask] + c[j]);
			}
		}
		ans = min(ans, dp[0]);
	}
	printf("%d", ans);
	return 0;
}