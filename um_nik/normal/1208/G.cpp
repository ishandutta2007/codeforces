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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 6;
int mu[N];
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 1) {
		printf("3\n");
		return 0;
	}
	k += 2;
	mu[1] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 2 * i; j < N; j += i)
			mu[j] -= mu[i];
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			a[j] += i * mu[j / i];
//	for (int i = 1; i <= n; i++) {
//		eprintf("%d %d\n", mu[i], a[i]);
//	}
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i <= k; i++)
		ans += a[i];
	printf("%lld\n", ans);

	return 0;
}