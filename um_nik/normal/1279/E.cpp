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

const ll INF = (ll)1e18 + 55;
ll add(ll x, ll y) {
	return min(INF, x + y);
}
ll mult(ll x, ll y) {
	if (INF / x < y) return INF;
	return min(INF, x * y);
}

const int N = 52;
ll f[N];
ll P[N];

vector<int> getCycle(int s, ll k) {
	vector<int> res;
	res.resize(s);
	for (int i = 0; i < s; i++)
		res[i] = -1;
	res[0] = s - 1;
	if (s == 1) return res;
	for (int i = 1; i < s; i++) {
		for (int x = 0; x < s; x++) {
			bool ok = true;
			for (int j = 0; j < i; j++)
				ok &= res[j] != x;
			if (!ok) continue;
			if (i == s - 1) {
				res[i] = x;
				break;
			}
			int p = x;
			while(p < i) p = res[p];
			if (p == i) continue;
			ll w = (i == s - 1 ? 1 : f[s - 2 - i]);
			if (w <= k) {
				k -= w;
				continue;
			}
			res[i] = x;
			break;
		}
	}
	return res;
}

vector<int> solve(int n, ll k) {
//	eprintf("solve %d %lld\n", n, k);
	vector<int> res;
	res.resize(n);
	if (n == 0) return res;
	for (int s = 0; s < n; s++) {
		ll w = mult((s == 0 ? 1 : f[s - 1]), P[n - s - 1]);
		if (w <= k) {
			k -= w;
			continue;
		}
		vector<int> cur;
		cur = getCycle(s + 1, k / P[n - s - 1]);
		for (int i = 0; i <= s; i++)
			res[i] = cur[i];
		cur = solve(n - s - 1, k % P[n - s - 1]);
		for (int i = 0; i < n - s - 1; i++)
			res[s + 1 + i] = cur[i] + s + 1;
		return res;
	}
	throw;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(i, f[i - 1]);

	P[0] = 1;
	for (int n = 1; n < N; n++) {
		P[n] = P[n - 1];
		for (int s = 2; s <= n; s++)
			P[n] = add(P[n], mult(f[s - 2], P[n - s]));
	}

	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		ll k;
		scanf("%d%lld", &n, &k);
		k--;
		if (k >= P[n]) {
			printf("-1\n");
			continue;
		}
		vector<int> ans = solve(n, k);
		for (int x : ans)
			printf("%d ", x + 1);
		printf("\n");
	}

	return 0;
}