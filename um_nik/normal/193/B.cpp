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

const int N = 33;
int a[N][N];
int b[N];
int k[N];
int p[N];
ll ans = -(ll)1e15;
int n, m, r;

void brute(int w, int lst) {
	if (w % 2 == m % 2) {
		ll cur = 0;
		for (int i = 0; i < n; i++)
			cur += (ll)a[w][i] * k[i];
		ans = max(ans, cur);
	}
	if (w == m) return;
	if (lst == 0) {
		for (int i = 0; i < n; i++)
			a[w + 1][i] = a[w][i] ^ b[i];
		brute(w + 1, 1);
	}
	for (int i = 0; i < n; i++)
		a[w + 1][i] = a[w][p[i]] + r;
	brute(w + 1, 0);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	brute(0, 0);
	printf("%lld\n", ans);

	return 0;
}