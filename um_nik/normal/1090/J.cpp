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
int z[N];
int pi[N];
char s[N], p[N];
int n, m, k;
int a[N];
int b[N];

void calcZ() {
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
}

void calcPi() {
	for (int i = 1; i < n; i++) {
		int x = pi[i];
		while(x > 0 && s[x] != s[i]) x = pi[x];
		if (x != 0) {
			pi[i + 1] = x + 1;
		} else if (s[i] == s[0])
			pi[i + 1] = 1;
		else
			pi[i + 1] = 0;
	}
}

ll solve() {
	s[k] = '#';
	for (int i = 0; i < m; i++)
		s[k + 1 + i] = p[i];
	n = m + k + 1;

	calcZ();
	int r = 1;
	for (int i = 1; i < k; i++) {
		r = max(r, i + 1);
		while (r <= i + z[i])
			b[r++] = i;
	}
/*
	calcPi();
	for (int i = k + 2; i <= n; i++) {
		int x = pi[i];
		if (x == i - (k + 1)) x = pi[x];
		a[x]++;
	}
	for (int i = k; i > 0; i--)
		a[pi[i]] += a[i];
*/
	for (int i = k + 2; i < n; i++)
		a[z[i]]++;
	for (int i = k; i > 0; i--)
		a[i - 1] += a[i];

	for (int i = 0; i <= k; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	for (int i = 0; i <= k; i++)
		eprintf("%d ", b[i]);
	eprintf("\n");

	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		if (b[i] == 0)
			ans += m;
		else
			ans += m - a[b[i]];
	}
	return ans;
}

ll stupid() {
	set<string> aaa;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++) {
			string w = "";
			for (int h = 0; h < i; h++)
				w += p[h];
			for (int h = 0; h < j; h++)
				w += s[h];
			aaa.insert(w);
		}
	return (ll)aaa.size();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s %s", p, s);
	m = strlen(p);
	k = strlen(s);

	ll ans = solve();
/*
	ll ans2 = stupid();
	if (ans != ans2) {
		eprintf("%s\n", s);
		eprintf("%lld %lld\n", ans, ans2);
		throw;
	}
*/
	printf("%lld\n", ans);

	return 0;
}