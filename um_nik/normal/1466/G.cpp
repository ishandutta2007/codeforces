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
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int M = (int)1e6 + 277;
const int N = (int)1e5 + 277;
const int A = 26;
int suf[A][N];
char t[N];
char p[N];
char s[M];
int n, m, k, L;
int p2[N];
int ans;

void brute(int p, int z, int len) {
	if (p >= L) return;
	if (z + len >= m) {
		int c = (int)(s[z] - 'a');
		ans = add(ans, sub(suf[c][p], suf[c][L]));
		return;
	}
	for (int it = 0; it < 2; it++) {
		bool ok = true;
		for (int i = z + it * len; ok && i < m; i += 2 * len)
			ok &= s[i] == t[p - 1];
		if (!ok) continue;
		brute(p + 1, z + (it ^ 1) * len, len * 2);
	}
}

void solve() {
	ans = 0;
	scanf("%d %s", &L, s);
	m = strlen(s);
	L++;
	for (int sh = 0; sh <= k; sh++) {
		bool ok = true;
		for (int i = 0, j = sh; ok && i < m; i++, j++) {
			if (j == k + 1) j = 0;
			if (j == k) continue;
			ok &= s[i] == p[j];
		}
		if (!ok) continue;
		int z = k - sh;
		if (z >= m) {
			ans = add(ans, p2[n]);
			continue;
		}
		brute(1, z, k + 1);
	}
	ans = mult(ans, rev(p2[(n + 1) - L]));
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = add(p2[i - 1], p2[i - 1]);
	int q;
	scanf("%d%d", &n, &q);
	scanf("%s", p);
	k = strlen(p);
	scanf("%s", t);
	for (int i = n - 1; i >= 0; i--) {
		for (int c = 0; c < A; c++)
			suf[c][i + 1] = suf[c][i + 2];
		suf[(int)(t[i] - 'a')][i + 1] = add(suf[(int)(t[i] - 'a')][i + 1], p2[n - 1 - i]);
	}
	while(q--) solve();

	return 0;
}