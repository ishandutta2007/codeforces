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

ll s;
ll a[N];
int p[N];
int deg[N];

ll getMin(ll n, ll k) {
	ll res = 1;
	ll m = 1;
	ll h = 1;
	n--;
	while(n > 0) {
		m *= k;
		m = min(m, n);
		h++;
		res += h * m;
		n -= m;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	scanf("%lld%lld", &n, &s);
	if (s > n * (n + 1) / 2) {
		printf("No\n");
		return 0;
	}
	if (s < 2 * n - 1) {
		printf("No\n");
		return 0;
	}
	int k = 1;
	while(getMin(n, k) > s) k++;
	for (int i = 1; i <= n; i++)
		a[i] = 1;
	s = n * (n + 1) / 2 - s;
	int pos = 2;
	for (int i = n; s > 0; i--) {
		while(a[pos] / k >= a[pos - 1]) pos++;
		if (i - pos <= s) {
			s -= i - pos;
			a[pos]++;
			a[i]--;
			continue;
		}
		a[i - s]++;
		a[i]--;
		break;
	}
	/*
	eprintf("k = %d\n", k);
	for (int i = 1; i <= n; i++)
		eprintf("%lld ", a[i]);
	eprintf("\n");
	*/
	int l = 0, r = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) break;
		int nl = r;
		int nr = nl + a[i];
		for (int v = nl; v < nr; v++) {
			if (deg[l] == k) l++;
			p[v] = l;
			deg[l]++;
		}
		l = nl;
		r = nr;
	}
	printf("Yes\n");
	for (int i = 1; i < n; i++)
		printf("%d ", p[i] + 1);
	printf("\n");

	return 0;
}