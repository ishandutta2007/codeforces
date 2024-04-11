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
ll s;

void solve() {
	scanf("%d%lld", &n, &s);
	ll sum = 0, m = 0;
	int id = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		sum += x;
		if (m < x) {
			m = x;
			id = i + 1;
		}
		if (sum <= s) {
			ans = 0;
		} else if (sum - m <= s) {
			ans = id;
		}
	}
	printf("%d\n", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}