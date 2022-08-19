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

const int N = 5010;
ll C[N][N];
ll rev[N];
ll ANS = 0;
ll a[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);

	rev[1] = 1;
	for (ll x = 2; x < N; x++)
		rev[x] = (MOD - rev[MOD % x] * (MOD / x) % MOD) % MOD;

	cin >> n >> m;

	ll curC = bin_pow(2, n);
	for (int k = 1; k <= min(n, m); k++) {
		curC = mult(curC, n + 1 - k);
		curC = mult(curC, rev[k]);
		curC = mult(curC, rev[2]);

		a[k] = bin_pow(k, m);
		for (int i = 1; i < k; i++)
			a[k] = sub(a[k], mult(C[k][i], a[i]));
		ANS = add(ANS, mult(curC, a[k]));
	}
	
	cout << ANS << endl;

	return 0;
}