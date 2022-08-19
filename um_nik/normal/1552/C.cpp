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

const int N = 303;
int n, k;
int a[N][2];
int pref[N];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 2 * n; i++)
		pref[i] = 1;
	pref[0] = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		pref[a[i][0]] = pref[a[i][1]] = 0;
	}
	for (int i = 1; i <= 2 * n; i++)
		pref[i] += pref[i - 1];
	int ans = (n - k) * (n - k - 1) / 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < i; j++) {
			int x = a[i][0], y = a[i][1];
			int l = a[j][0], r = a[j][1];
			if (x > y) swap(x, y);
			if (l > r) swap(l, r);
			if (x > l) {
				swap(x, l);
				swap(y, r);
			}
			ans += (int)(l < y && y < r);
		}
	for (int i = 0; i < k; i++) {
		int l = a[i][0], r = a[i][1];
		if (l > r) swap(l, r);
		int c = pref[r] - pref[l];
		c = min(c, 2 * (n - k) - c);
		ans += c;
	}
	printf("%d\n", ans);
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