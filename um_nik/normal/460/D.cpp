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


int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll L, R;
	int k;
	scanf("%lld%lld%d", &L, &R, &k);
	if (L == 0) {
		printf("0\n1\n0\n");
		return 0;
	}

	if (k == 1) {
		printf("%lld\n1\n%lld\n", L, L);
		return 0;
	} else if (k == 2) {
		ll X = L;
		if (X & 1) X++;
		if (X + 1 <= R) {
			printf("1\n2\n%lld %lld\n", X, X + 1);
			return 0;
		}
		assert(L + 1 == R);
		if (L < (L ^ R)) {
			printf("%lld\n1\n%lld\n", L, L);
		} else {
			printf("%lld\n2\n%lld %lld\n", L ^ R, L, R);
		}
		return 0;
	} else if (k == 3) {
		ll X = L;
		if (X & 1) X++;
		for (int t = 1; (1LL << t) < R; t++) {
			if ((1LL << t) <= L) continue;
			int p = 0;
			while(p + 1 < t && (1LL << t) + (1LL << (p + 1)) <= R) p++;
			ll Y = (1LL << (p + 1)) - 1;
			if (Y >= L) {
				ll Z = (1LL << t) + (1LL << p);
				printf("0\n3\n%lld %lld %lld\n", Y, Z - 1, Z);
				return 0;
			}
		}
		printf("1\n2\n%lld %lld\n", X, X + 1);
		return 0;
	} else {
		ll X = L;
		while(X % 4 != 0) X++;
		if (X + 3 <= R) {
			printf("0\n4\n%lld %lld %lld %lld\n", X, X + 1, X + 2, X + 3);
			return 0;
		}
		int sz = (R - L + 1);
		assert(sz < 12);
		for (int mask = 1; mask < (1 << sz); mask++) {
			int ppc = 0;
			ll Y = 0;
			for (int i = 0; i < sz; i++) {
				if ((mask >> i) & 1) {
					ppc++;
					Y ^= L + i;
				}
			}
			if (ppc <= k && Y == 0) {
				printf("0\n%d\n", ppc);
				for (int i = 0; i < sz; i++) {
					if ((mask >> i) & 1) {
						printf("%lld ", L + i);
					}
				}
				printf("\n");
				return 0;
			}
		}
		if (X - 2 >= L)
			X -= 2;
		
		printf("1\n2\n%lld %lld\n", X, X + 1);
		return 0;
	}

	return 0;
}