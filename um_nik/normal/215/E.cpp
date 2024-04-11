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

const int Z = 61;
ll mu[Z];

ll solve(int len, ll R) {
//	eprintf("solve %d %lld\n", len, R);
	ll ans = 0;
	for (int k = 2; k <= len; k++) {
		if (len % k) continue;
		ll t = ((1LL << len) - 1) / ((1LL << (len / k)) - 1);
		ll l = (1LL << (len / k - 1)) - 1;
		ll r = 1LL << (len / k);
		while(r - l > 1) {
			ll x = (l + r) / 2;
			if (x * t >= R)
				r = x;
			else
				l = x;
		}
		ans -= mu[k] * (r - (1LL << (len / k - 1)));
	}
//	eprintf("%lld\n", ans);
	return ans;
}

ll solve(ll R) {
	R++;
	ll ans = 0;
	for (int len = 1; len < Z; len++) {
		if (1LL << (len - 1) >= R) break;
		ans += solve(len, min(R, 1LL << len));
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	mu[1] = 1;
	for (int i = 1; i < Z; i++)
		for (int j = 2 * i; j < Z; j += i)
			mu[j] -= mu[i];

	ll l, r;
	scanf("%lld%lld", &l, &r);
	l--;
	printf("%lld\n", solve(r) - solve(l));

	return 0;
}