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

	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll sum = 0, sumEven = 0;
	ll w = 0;
	while(k--) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		sum += y;
		if (x % 2 == 0) sumEven += y;
		w += x * y;
		w %= n;
	}
	if (sum > n) {
		printf("-1\n");
		return 0;
	}
	if (sum < n) {
		printf("1\n");
		return 0;
	}
	if (w != ((n * (n + 1)) / 2) % n) {
		printf("-1\n");
		return 0;
	}
	if (n % 2 == 0) {
		if (sumEven % 2 != (n / 2) % 2) {
			printf("-1\n");
		} else {
			printf("1\n");
		}
	} else {
		printf("1\n");
	}

	return 0;
}