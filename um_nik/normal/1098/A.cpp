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

const int N = 100100;
int n;
int p[N];
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i > 0 && a[i] != -1) {
			if (a[p[i]] == -1)
				a[p[i]] = a[i];
			else
				a[p[i]] = min(a[p[i]], a[i]);
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == -1)
			a[i] = a[p[i]];
		if (a[i] < a[p[i]]) {
			printf("-1\n");
			return 0;
		}
	}
	ll ans = a[0];
	for (int i = 1; i < n; i++)
		ans += a[i] - a[p[i]];
	printf("%lld\n", ans);

	return 0;
}