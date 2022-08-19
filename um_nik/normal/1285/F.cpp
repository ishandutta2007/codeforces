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

const int N = (int)1e5 + 2;
int a[N];
int n;
ll ans = 0;
vector<int> d[N];
vector<int> p[N];
vector<int> pp[N];
vector<int> b[N];
int perm[N];
int cnt[N];
int ppc[N];

void precalc() {
	for (int x = 1; x < N; x++)
		for (int y = x; y < N; y += x)
			d[y].push_back(x);
	for (int x = 2; x < N; x++) {
		if (!p[x].empty()) continue;
		for (int y = x; y < N; y += x)
			p[y].push_back(x);
	}
	for (int x = 1; x < N; x++) {
		int m = (int)p[x].size();
		pp[x].resize(1 << m);
		pp[x][0] = 1;
		for (int mask = 1; mask < (1 << m); mask++) {
			int k = 0;
			while(((mask >> k) & 1) == 0) k++;
			pp[x][mask] = pp[x][mask ^ (1 << k)] * p[x][k];
		}
	}
	for (int i = 1; i < N; i++)
		ppc[i] = ppc[i >> 1] ^ (i & 1);
}

void add(int x) {
	for (int y : pp[x])
		cnt[y]++;
}
int get(int x) {
	int res = 0;
	for (int mask = 0; mask < (int)pp[x].size(); mask++) {
		if (ppc[mask])
			res -= cnt[pp[x][mask]];
		else
			res += cnt[pp[x][mask]];
	}
	return res;
}

bool check(vector<int> &c, ll w) {
	int m = c.back();
	for (int i = 1; i <= m; i++)
		cnt[i] = 0;
	int pos = (int)c.size();
	for (int i = 0; i < (int)c.size(); i++) {
		while(pos > 0 && (ll)c[i] * c[pos - 1] >= w) {
			pos--;
			add(c[pos]);
		}
		if (get(c[i]) > 0) return true;
	}
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	precalc();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	ans = a[n - 1];

	for (int i = 0; i < n; i++)
		for (int g : d[a[i]])
			b[g].push_back(a[i] / g);

	for (int i = 0; i < N; i++)
		perm[i] = i;
	shuffle(perm, perm + N, rng);
	for (int i = 0; i < N; i++) {
		int g = perm[i];
		if ((int)b[g].size() < 2) continue;
		ll want = ans / g + 1;
		if (!check(b[g], want)) continue;
		ll l = want, r = (ll)b[g][(int)b[g].size() - 1] * b[g][(int)b[g].size() - 2] + 1;
		while(r - l > 1) {
			ll x = (l + r) / 2;
			if (check(b[g], x))
				l = x;
			else
				r = x;
		}
		ans = l * g;
	}
	printf("%lld\n", ans);

	return 0;
}