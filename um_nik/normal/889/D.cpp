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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

ll gcd(ll x, ll y) {
	return (y == 0 ? x : gcd(y, x % y));
}

set<pll> setik;
const int N = 2020;
pll a[N];
int n;
pll C;
pll b[N];
ll p[N];

bool solve(ll x, ll y) {
	for (int i = 0; i < n; i++)
		p[i] = a[i].first * x + a[i].second * y;
	sort(p, p + n);
	ll S = p[0] + p[n - 1];
	for (int i = 0; i < n; i++)
		if (p[i] + p[n - 1 - i] != S)
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	C = mp(0LL, 0LL);
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		C.first += x;
		C.second += y;
		x *= 2 * n;
		y *= 2 * n;
		a[i] = mp(x, y);
		setik.insert(a[i]);
	}
	C.first *= 2;
	C.second *= 2;

	while(!setik.empty()) {
		pll t = *setik.begin();
		if (t == C) {
			setik.erase(setik.begin());
			continue;
		}
		pll t2 = mp(2 * C.first - t.first, 2 * C.second - t.second);
		if (setik.count(t2) != 0) {
			setik.erase(t);
			setik.erase(t2);
			continue;
		}
		break;
	}
	if (setik.empty()) {
		printf("-1\n");
		return 0;
	}
	int m = 0;
	pll t1 = *setik.begin();
	for (auto t2 : setik) {
		b[m++] = mp((t1.first + t2.first) / 2 - C.first, (t1.second + t2.second) / 2 - C.second);
	}
	for (int i = 0; i < m; i++) {
		if (b[i].first < 0 || (b[i].first == 0 && b[i].second < 0)) {
			b[i].first *= -1;
			b[i].second *= -1;
		}
		ll g = gcd(abs(b[i].first), abs(b[i].second));
		b[i].first /= g;
		b[i].second /= g;
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (solve(-b[i].second, b[i].first))
			ans++;
	printf("%d\n", ans);

	return 0;
}