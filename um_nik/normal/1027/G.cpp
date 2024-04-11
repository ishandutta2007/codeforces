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

const ll B = (ll)1e4;
ll mult(ll x, ll y, ll mod) {
	if (y == 0) return 0;
	return (mult(x, y / B, mod) * B + x * (y % B)) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1 % mod;
	if (p & 1) return mult(x, bin_pow(x, p - 1, mod), mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}
ll lcm(ll x, ll y) {
	return x * (y / gcd(x, y));
}

const int N = 50;
int n;
ll P[N][2];
ll a[N][N][2];

vector<pll> factorize(ll m) {
	vector<pll> res;
	for (ll y = 2; y * y <= m; y++) {
		if (m % y) continue;
		res.push_back(mp(y, 0LL));
		while(m % y == 0) {
			res.back().second++;
			m /= y;
		}
		n++;
	}
	if (m > 1) {
		res.push_back(mp(m, 1LL));
	}
	return res;
}

ll ans;
void brute(int pos, ll PP, ll Q) {
//	eprintf("brute %d %lld %lld\n", pos, PP, Q);
	if (pos == n) {
		ans += PP / Q;
		return;
	}
	for (int i = 0; i <= P[pos][1]; i++) {
		brute(pos + 1, PP * a[pos][i][0], lcm(Q, a[pos][i][1]));
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll m, x;
	cin >> m >> x;

	vector<pll> q = factorize(m);
	n = (int)q.size();
	for (int i = 0; i < n; i++) {
		P[i][0] = q[i].first;
		P[i][1] = q[i].second;
	}

//	eprintf("%d\n", n);
//	for (int i = 0; i < n; i++)
//		eprintf("%lld %lld\n", P[i][0], P[i][1]);
//	return 0;

	ans = 0;
	for (int i = 0; i < n; i++) {
		ll mod = 1;
		q = factorize(P[i][0] - 1);
		for (int pw = 0; pw <= P[i][1]; pw++) {
			if (pw == 0) {
				a[i][pw][0] = a[i][pw][1] = 1;
				continue;
			}
			mod *= P[i][0];
			ll cur = mod - mod / P[i][0];
			for (int j = 0; j < (int)q.size(); j++) {
				for (int k = 0; k < q[j].second; k++) {
					ll ncur = cur / q[j].first;
					if (bin_pow(x, ncur, mod) != 1) break;
					cur = ncur;
				}
			}
			for (int k = 0; k < pw - 1; k++) {
				ll ncur = cur / P[i][0];
				if (bin_pow(x, ncur, mod) != 1) break;
				cur = ncur;
			}
			a[i][pw][0] = mod - mod / P[i][0];
			a[i][pw][1] = cur;
		}
	}
	brute(0, 1, 1);
	printf("%lld\n", ans);

	return 0;
}