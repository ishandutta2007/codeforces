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
#define mp make_pair

struct Item {
	ll cnt;
	ll a, b;

	Item() : cnt(), a(), b() {}

	void scan() {
		scanf("%lld%lld%lld", &cnt, &a, &b);
	}

	bool operator < (const Item &I) const {
		return a - b > I.a - I.b;
	}
};

const int N = 100100;
int n;
ll s;
Item a[N];
Item b[N];
ll sum;
ll C;

ll solve(ll D) {
	if (D > C) return 0;
	ll E = C - D;
	D *= s;
	E *= s;
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	ll ans = 0;
	int p = 0;
	while(p < n && b[p].a > b[p].b && D > 0) {
		ll X = min(D, b[p].cnt);
		b[p].cnt -= X;
		D -= X;
		ans += X * b[p].a;
		if (b[p].cnt == 0) p++;
	}
	int q = n;
	while(q > 0 && b[q - 1].b > b[q - 1].a && E > 0) {
		ll X = min(E, b[q - 1].cnt);
		b[q - 1].cnt -= X;
		E -= X;
		ans += X * b[q - 1].b;
		if (b[q - 1].cnt == 0) q--;
	}
	for (int i = p; i < q; i++) {
		ll X = min(D, b[i].cnt);
		D -= X;
		b[i].cnt -= X;
		ans += X * b[i].a;
		X = min(E, b[i].cnt);
		E -= X;
		b[i].cnt -= X;
		ans += X * b[i].b;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &s);
	for (int i = 0; i < n; i++) {
		a[i].scan();
		sum += a[i].cnt;
	}
	sort(a, a + n);
	C = (sum + s - 1) / s;
	int it = 0;
	sum = 0;
	while(it < n && a[it].a > a[it].b) {
		sum += a[it].cnt;
		it++;
	}
	printf("%lld\n", max(solve(sum / s), solve(sum / s + 1)));

	return 0;
}