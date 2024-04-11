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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll MOD = (ll)1e9 + 7;

const int N = (int)5e6 + 77;
int n, m;
int a[N];
int t[N];
int ans[N];
int nxt[N];

ll seed, base;

ll rrr() {
	ll ret = seed;
	seed = (seed * base + 233) % ((ll)1e9 + 7);
	return ret;
}

void read() {
	scanf("%d%d", &n, &m);
	int pos = 0;
	while(m--) {
		ll p, k, b, w;
		scanf("%lld%lld%lld%lld", &p, &k, &b, &w);
		seed = b;
		base = w;
		while(pos < p) {
			t[pos] = rrr() % 2;
			a[pos] = rrr() % k + 1;
			pos++;
		}
	}
}

int getNextOne(int v) {
	return (t[v] == 1 && a[v] > 0 ? v : nxt[v] = getNextOne(nxt[v]));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();

	ll tot0 = 0, tot1 = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == 0)
			tot0 += a[i];
		else
			tot1 += a[i];
	}
	if (tot1 < tot0) {
		for (int i = 0; i < n; i++)
			t[i] ^= 1;
	}
	for (int i = 0; i < n; i++) {
		nxt[i] = i + 1;
	}
	nxt[n - 1] = 0;
	if (t[0] == 1) {
		a[0]--;
		ans[0]++;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == 1) continue;
		int v = i;
		int lft = a[i];
		ans[i] = a[i];
		while(lft > 0) {
			v = getNextOne(v);
			int x = min(lft, a[v]);
			ans[v] += x;
			lft -= x;
			a[v] -= x;
		}
	}
	ll res = 1;
	for (int i = 0; i < n; i++) {
		ll cur = ans[i];
		cur ^= (ll)(i + 1) * (i + 1);
		cur += 1;
		cur %= MOD;
		res = (res * cur) % MOD;
//		eprintf("%d ", ans[i]);
//		eprintf("\n");
	}
	printf("%lld\n", res);

	return 0;
}