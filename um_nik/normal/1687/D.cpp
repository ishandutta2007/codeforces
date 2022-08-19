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

const int N = (int)1e6 + 7;
int a[N];
int n;
int jmp[N];

int myJump(int v, int x) {
	if (jmp[v] != v) return jmp[v] = myJump(jmp[v], x);
	if (v == n - 1 || a[v + 1] - a[v] > x) return v;
	return jmp[v] = myJump(v + 1, x);
}

ll mySqrt(ll x) {
	ll y = (ll)sqrt(x);
	while(y * y < x) y++;
	while(y * y > x) y--;
	return y;
}
void solve(ll x, ll y, ll &L, ll &R) {
	ll z = x + L;
	ll k = mySqrt(z);
	if (k * k + k < z) k++;
	L = max(L, k * k - x);
	R = min(R, k * k + k - y);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		jmp[i] = i;
	}
	for (ll k = 1;; k++) {
		ll L = k * k - a[0], R = k * k + k - a[0];
		if (R < 0) continue;
		if (L < 0) L = 0;
		int v = 0;
		while(L <= R && v < n) {
			int u = myJump(v, k);
			solve(a[v], a[u], L, R);
			v = u + 1;
		}
		if (L <= R) {
			printf("%lld\n", L);
			return 0;
		}
	}

	return 0;
}