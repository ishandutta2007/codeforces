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

const int INF = (int)1e9 + 5;
const int K = 6;
const int N = 100100;
int n;
int a[K];
int b[N];
int ans = INF;

int solve(int m) {
	if (b[0] - a[0] < m) return INF;
	int res = 0;
	for (int i = 0; i < K; i++) {
		int p = n;
		if (i + 1 < K)
			p = lower_bound(b, b + n, m + a[i + 1]) - b;
		if (p > 0)
			res = max(res, b[p - 1] - a[i]);
	}
	return res - m;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < K; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + K);
	sort(b, b + n);
	for (int i = 0; i < K; i++)
		for (int j = 0; j < n; j++)
			ans = min(ans, solve(b[j] - a[i]));
	printf("%d\n", ans);

	return 0;
}