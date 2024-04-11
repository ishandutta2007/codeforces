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

const int N = (int)1e6 + 7;
ll a[N], b[N];
int c[N];
ll ans;
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
			scanf("%d", &c[j]);
		bool ok = false;
		for (int j = 1; j < k; j++)
			ok |= c[j] > c[j - 1];
		if (ok) {
			m++;
		} else {
			a[c[0]]++;
			b[c[k - 1]]++;
		}
	}
	ans = (ll)n * n - (ll)(n - m) * (n - m);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		ans += sum * a[i];
		sum += b[i];
	}
	printf("%lld\n", ans);

	return 0;
}