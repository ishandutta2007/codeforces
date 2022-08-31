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

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 1010;
int n;
char s[N];
int col[N][2];

bool dfs(int x, int y, int p) {
	if (s[x] != '?') {
		int val = col[x][y] ^ (int)(s[x] - '0');
		if (col[x][y ^ 1] == -1) {
			col[x][y ^ 1] = val;
			if (!dfs(x, y ^ 1, p)) return false;
		} else if (col[x][y ^ 1] != val) return false;
	}
	int val = col[x][y];
	if (y == 0) {
		x = n - 1 - x;
		if (col[x][y] == -1) {
			col[x][y] = val;
			if (!dfs(x, y, p)) return false;
		} else if (col[x][y] != val) return false;
	} else {
		if (x < p) return true;
		x = n - 1 - (x - p);
		if (col[x][y] == -1) {
			col[x][y] = val;
			if (!dfs(x, y, p)) return false;
		} else if (col[x][y] != val) return false;
	}
	return true;
}

ll solve(int p) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++) {
			col[i][j] = -1;
		}
	col[0][0] = col[p][1] = 1;
	col[n - 1][0] = col[n - 1][1] = 1;
	for (int i = 0; i < p; i++)
		col[i][1] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++) {
			if (col[i][j] == -1) continue;
			if (!dfs(i, j, p)) return 0;
		}
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (col[i][j] != -1) continue;
			col[i][j] = 0;
			if (!dfs(i, j, p)) return 0;
			ans = add(ans, ans);
		}
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	/*
	if (s[n - 1] == '?')
		s[n - 1] = '0';
	if (s[n - 1] != '0') {
		printf("0\n");
		return 0;
	}
	*/
	ll ans = 0;
	for (int p = 1; p < n; p++)
		ans = add(ans, solve(p));
	printf("%lld\n", ans);

	return 0;
}