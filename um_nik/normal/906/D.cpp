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
typedef pair<ll, bool> plb;
#define mp make_pair

const int N = 100100;
int n;
ll mods[N];
int m;
ll a[N];

ll getPhi(ll x) {
	ll phi = 1;
	for (ll d = 2; d * d <= x; d++) {
		if (x % d != 0) continue;
		phi *= d - 1;
		x /= d;
		while(x % d == 0) {
			x /= d;
			phi *= d;
		}
	}
	if (x > 1) phi *= x - 1;
	return phi;
}

plb mult(plb x, plb y, ll mod) {
	plb res = mp(x.first * y.first, x.second | y.second);
	if (res.first >= mod) {
		res.first %= mod;
		res.second = 1;
	}
	return res;
}
plb bin_pow(plb x, ll p, ll mod) {
	if (p == 0)
		return mp(1 % mod, 1 >= mod);
	if (p & 1) return mult(x, bin_pow(x, p - 1, mod), mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

plb solve(int L, int R, int mid) {
	if (mods[mid] == 1)
		return mp(0, 1);
	if (L >= R)
		return mp(1, 0);
	plb pw = solve(L + 1, R, mid + 1);
	return bin_pow(mp(a[L] % mods[mid], a[L] >= mods[mid]), pw.first + (pw.second ? mods[mid + 1] : 0), mods[mid]);
}

void query() {
	int L, R;
	scanf("%d%d", &L, &R);
	L--;
	printf("%lld\n", solve(L, R, 0).first);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &mods[0]);
	m = 1;
	while(mods[m - 1] > 1) {
		mods[m] = getPhi(mods[m - 1]);
		m++;
	}
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	int q;
	scanf("%d", &q);
	while(q--) query();

	return 0;
}