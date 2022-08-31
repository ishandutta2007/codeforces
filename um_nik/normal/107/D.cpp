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


const ll MOD = 12345;
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

const int L = 61;
const int A = 26;
const int N = 144;
vector<int> z[A];
vector<int> b[A];
int h[A];
ll M[L][N][N];
ll w[2][N];

bool isGood(int x) {
	for (int c = 0; c < A; c++) {
		if (h[c] == -1) continue;
		int y = x % (int)b[c].size();
		x /= (int)b[c].size();
		if (b[c][y] == 0) return false;
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n;
	int m;
	scanf("%lld%d", &n, &m);
	while(m--) {
		char t;
		int w;
		scanf(" %c %d", &t, &w);
		int c = (int)(t - 'A');
		z[c].push_back(w);
	}
	for (int c = 0; c < A; c++) {
		if (z[c].empty()) continue;
		int L = 1;
		for (int x : z[c]) L = lcm(L, x);
		b[c] = vector<int>(L, 0);
		for (int x : z[c]) {
			for (int i = 0; i < L; i += x)
				b[c][i] = 1;
		}
	}
	int S = 1;
	for (int c = 0; c < A; c++) {
		h[c] = -1;
		if (b[c].empty()) continue;
		h[c] = S;
		S *= (int)b[c].size();
	}
	assert(S < N);
	for (int x = 0; x < S; x++) {
		for (int c = 0; c < A; c++) {
			if (h[c] == -1) continue;
			int y = (x / h[c]);
			y %= (int)b[c].size();
			if (y + 1 == (int)b[c].size()) {
				y = x - h[c] * ((int)b[c].size() - 1);
			} else {
				y = x + h[c];
			}
			M[0][x][y]++;
		}
	}
	for (int k = 0; k + 1 < L; k++) {
		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++) {
				M[k + 1][i][j] = 0;
				for (int h = 0; h < S; h++)
					M[k + 1][i][j] = add(M[k + 1][i][j], mult(M[k][i][h], M[k][h][j]));
			}
	}
	w[0][0] = 1;
	for (int k = 0; k < L; k++) {
		if (((n >> k) & 1) == 0) continue;
		for (int i = 0; i < S; i++)
			w[1][i] = 0;
		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++)
				w[1][j] = add(w[1][j], mult(w[0][i], M[k][i][j]));
		for (int i = 0; i < S; i++)
			w[0][i] = w[1][i];
	}
	ll ans = 0;
	for (int x = 0; x < S; x++)
		if (isGood(x))
			ans = add(ans, w[0][x]);
	printf("%lld\n", ans);

	return 0;
}