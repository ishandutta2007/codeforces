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
ll a[N];
ll pref[N], suf[N];
int n;

bool solve() {
	scanf("%d", &n);
	n += 2;
	a[0] = a[n - 1] = 0;
	for (int i = 1; i < n - 1; i++)
		scanf("%lld", &a[i]);
	pref[0] = 0;
	bool ok = true;
	for (int i = 1; i < n; i++) {
		ll x = a[i - 1] - pref[i - 1];
		ok &= x <= a[i];
		if (ok)
			pref[i] = x;
		else
			pref[i] = -1;
	}
	ok = true;
	suf[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		ll x = a[i + 1] - suf[i + 1];
		ok &= x <= a[i];
		if (ok)
			suf[i] = x;
		else
			suf[i] = -1;
	}
	if (suf[0] == a[0]) return true;
	//eprintf("here\n");
	for (int i = 1; i < n - 2; i++) {
		if (pref[i - 1] == -1) continue;
		if (suf[i + 2] == -1) continue;
		ll A = a[i - 1] - pref[i - 1];
		ll B = a[i + 1];
		ll C = a[i];
		ll D = a[i + 2] - suf[i + 2];
		//eprintf("%lld %lld %lld %lld\n", A, B, C, D);
		if (A > B || D > C) continue;
		if (B - A == C - D) return true;
	}
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}