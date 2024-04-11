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

const int N = 200200;
int n, q;
int a[N];
int ans[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		ans[i][0] = a[i];
		ans[i][1] = a[i + 1];
		a[n + i] = min(a[i], a[i + 1]);
		a[i + 1] = max(a[i], a[i + 1]);
	}
	while(q--) {
		ll t;
		scanf("%lld", &t);
		t--;
		if (t < n) {
			printf("%d %d\n", ans[t][0], ans[t][1]);
		} else {
			t -= n;
			t %= n - 1;
			printf("%d %d\n", a[n], a[n + 1 + t]);
		}
	}

	return 0;
}