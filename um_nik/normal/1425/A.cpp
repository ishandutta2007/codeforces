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

const int N = (int)1e5;
int dp[N];

ll solve(ll x) {
	assert(x % 2 == 0);
	if (x < N) return dp[x];
	if ((x / 2) % 2 == 1)
		return x / 2 + solve(x / 2 - 1);
	return 1 + (x - 2) / 2 + solve(x / 2 - 2);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 1; x < N; x++) {
		dp[x] = 1 + (x - 1 - dp[x - 1]);
		if (x % 2 == 0)
			dp[x] = max(dp[x], x / 2 + (x / 2 - dp[x / 2]));
	}

	int t;
	scanf("%d", &t);
	while(t--) {
		ll x;
		scanf("%lld", &x);
		if (x % 2 == 0) {
			printf("%lld\n", solve(x));
		} else {
			printf("%lld\n", 1 + (x - 1 - solve(x - 1)));
		}
	}

	return 0;
}