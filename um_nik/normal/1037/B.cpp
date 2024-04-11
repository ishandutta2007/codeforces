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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n;
ll a[N];
ll s;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n / 2; i++) {
		if (a[i] > s)
			ans += a[i] - s;
	}
	ans += abs(a[n / 2] - s);
	for (int i = n / 2 + 1; i < n; i++)
		if (a[i] < s)
			ans += s - a[i];
	printf("%lld\n", ans);

	return 0;
}