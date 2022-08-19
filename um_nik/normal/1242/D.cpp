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

const ll INF = (ll)2e18;
const int L = 96;
ll id[L];
ll st[L];
ll skp[L];
ll sum[L];
int m;

ll mult(ll x, ll y) {
	if (INF / x < y) return INF;
	return min(x * y, INF);
}

void build(ll k) {
	m = 0;
	id[m] = 0;
	st[m] = 1;
	skp[m] = -1;
	sum[m] = mult(st[m], k) + k * (k - 1) / 2;
	if (skp[m] != -1) sum[m] += st[m] + k - skp[m];
	sum[m] = min(sum[m], INF);
	m++;
	while(sum[m - 1] != INF) {
		if (m >= L - 2) throw;
		ll nw = st[m - 1] + k + min(skp[m - 1], 0LL) + 1;
		ll z = sum[m - 1] - nw;
		ll holes = 0;
		if (m > 1) holes = id[m - 1] - id[m - 2] - 1;
		ll full = (z - holes) / k;
		id[m] = id[m - 1] + full + 1;
		st[m] = nw + full * k + holes;
		if (st[m] == sum[m - 1]) st[m]++;
		if (sum[m - 1] >= st[m] + k) throw;
		if (sum[m - 1] > st[m])
			skp[m] = sum[m - 1];
		else
			skp[m] = -1;
		sum[m] = mult(st[m], k) + k * (k - 1) / 2;
		if (skp[m] != -1) sum[m] += st[m] + k - skp[m];
		sum[m] = min(sum[m], INF);
		m++;
	}
//	for (int i = 0; i < 5; i++)
//		eprintf("%lld %lld %lld %lld\n", id[i], st[i], skp[i], sum[i]);
}

pll findLast(int pos, ll n, ll k) {
//	eprintf("findLast %d %lld %lld\n", pos, n, k);
	if (sum[pos] > n) throw;
	if (sum[pos + 1] <= n) return mp(id[pos + 1], sum[pos + 1]);
	ll pp = (n - k * (k - 1) / 2) / k;
//	eprintf("pp = %lld\n", pp);
	if (pos == 0) {
		ll s = pp;
		s--;
		s -= s % k;
		s++;
		while(s / k >= id[pos + 1]) s -= k;
		ll sm = mult(s, k) + k * (k - 1) / 2;
		if (sm > n) throw;
		return mp(s / k, sm);
	}
	pll cur = findLast(pos - 1, pp + k - 1, k);
	ll nw = st[pos] + k + min(skp[pos], 0LL) + 1;
	if (cur.first == id[pos - 1]) {
		if (pp < nw) return mp(id[pos], sum[pos]);
		ll curId = id[pos] + 1;
		ll full = (pp - nw) / k;
		curId += full;
		nw += full * k;
		return mp(curId, nw * k + k * (k - 1) / 2);
	}
	ll holes = cur.first - id[pos - 1];
	ll z = (cur.second - nw);
	ll full = (z - holes + 1) / k;
	ll curId = id[pos] + full;
	nw += holes - 1 + full * k;
	if (nw > cur.second) throw;
	if (nw + k <= cur.second) throw;
	ll oldNw = nw;
	if (nw == cur.second) nw++;
	ll curSum = mult(nw, k) + k * (k - 1) / 2;
	if (nw <= cur.second) curSum += nw + k - cur.second;
	if (curSum > n) {
		if (full == 0) return mp(id[pos], sum[pos]);
		nw = oldNw;
		nw -= k;
		curSum = mult(nw, k) + k * (k - 1) / 2;
		if (curSum > n) throw;
		return mp(curId, curSum);
	}
	curId++;
	if (nw <= cur.second) nw++;
	nw += k;
	if (mult(nw, k) + k * (k - 1) / 2 > n) return mp(curId, curSum);
	curId++;
	curSum = mult(nw, k) + k * (k - 1) / 2;
	full = (n - curSum) / (k * k);
	curId += full;
	curSum += full * k * k;
	return mp(curId, curSum);
}

ll solve(ll n, ll k) {
	build(k);

	int pos = m - 1;
	while(st[pos] > n) pos--;
	if (n == sum[pos]) return (k + 1) * (id[pos] + 1);
	if (n == skp[pos]) return (k + 1) * (id[pos - 1] + 1);
	ll zz = n - st[pos] + 1;
	if (skp[pos] != -1 && n >= skp[pos]) zz--;
	if (zz <= k) return (k + 1) * id[pos] + zz;
	if (pos == 0) {
		ll full = (n - 1) / k;
		return full * (k + 1) + (n - 1) % k + 1;
	}
	pll ans = findLast(pos - 1, n, k);
//	eprintf("ans = (%lld, %lld)\n", ans.first, ans.second);
	if (ans.second == n) {
		return (k + 1) * (ans.first + 1);
	}
	ll nw = st[pos] + k + min(skp[pos], 0LL) + 1;
	ll holes = ans.first - id[pos - 1];
	ll z = n - nw;
	ll full = (z - holes) / k;
	ll myId = id[pos] + full + 1;
	z = (z - holes) % k + 1;
	return myId * (k + 1) + z;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	build(2);
//	return 0;

/*
	for (ll k = 2; k <= 3; k++) {
		for (ll n = 1; n <= 40; n++)
			printf("%lld %lld\n", n, solve(n, k));
	}
	return 0;
*/
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		printf("%lld\n", solve(n, k));
	}

	return 0;
}