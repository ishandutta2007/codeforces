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

const int N = 5050;
int n;
ll a[N];
ll b[N];
ll c[N];

void solve() {
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = c[i] = 0;
	}
	b[n] = 0;
	ll bal = 0;
	for (int i = 0; i < n; i++) {
		bal += b[i];
//		ll cur = bal;
		ll cur = bal + c[i];
		ans += max(0LL, a[i] - 1 - cur);
		c[i + 1] += max(0LL, cur - (a[i] - 1));
		b[i + 2] += 1;
		int p = min(i + a[i] + 1, (ll)n);
		b[p] -= 1;
	}
	printf("%lld\n", ans);
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