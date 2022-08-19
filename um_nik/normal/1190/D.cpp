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
pii a[N];
int xs[N];
int xsSz;
int n;
int fenv[N];
bool used[N];

void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}
int getSum(int l, int r) {
	return getFenv(r - 1) - getFenv(l - 1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].second, &a[i].first);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int i = 0; i < n; i++) {
		xs[xsSz++] = a[i].second;
	}
	sort(xs, xs + xsSz);
	xsSz = unique(xs, xs + xsSz) - xs;
	for (int i = 0; i < n; i++)
		a[i].second = lower_bound(xs, xs + xsSz, a[i].second) - xs;
	ll ans = 0;
	int l = 0;
	reverse(a, a + n);
	ll m = 0;
	while(l < n) {
		int r = l;
		while(r < n && a[l].first == a[r].first) r++;
		vector<int> z;
		for (int i = l; i < r; i++)
			z.push_back(a[i].second);
		z.push_back(-1);
		z.push_back(xsSz);
		sort(z.begin(), z.end());
		z.resize(unique(z.begin(), z.end()) - z.begin());
		for (int i = 0; i < (int)z.size() - 1; i++) {
			int L = z[i] + 1, R = z[i + 1];
			ll w = getSum(L, R);
			ans -= w * (w + 1) / 2;
		}
		while(l < r) {
			if (!used[a[l].second]) {
				m++;
				used[a[l].second] = 1;
				addFenv(a[l].second, 1);
			}
			l++;
		}
		ans += m * (m + 1) / 2;
	}
	printf("%lld\n", ans);

	return 0;
}