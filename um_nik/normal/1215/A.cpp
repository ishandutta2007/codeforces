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


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int a1, a2, k1, k2, n;
	scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
	int x = a1 * (k1 - 1) + a2 * (k2 - 1);
	printf("%d ", max(0, n - x));
	if (k1 > k2) {
		swap(a1, a2);
		swap(k1, k2);
	}
	int ans = 0;
	if (n <= a1 * k1) {
		ans = n / k1;
	} else {
		ans = a1 + (n - a1 * k1) / k2;
	}
	printf("%d\n", ans);

	return 0;
}