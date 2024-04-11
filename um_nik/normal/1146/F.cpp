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

const int N = 200200;
int n;
int p[N];
bool isLeaf[N];
ll dp[N][3];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		isLeaf[i] = true;
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		isLeaf[p[i]] = false;
	}
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int v = n - 1; v > 0; v--) {
		if (isLeaf[v]) {
			dp[v][0] = dp[v][1] = 1;
		} else {
			dp[v][0] = add(dp[v][0], dp[v][2]);
			dp[v][1] = add(dp[v][1], dp[v][2]);
		}
		int u = p[v];
		dp[u][2] = add(mult(dp[u][1], dp[v][1]), mult(dp[u][2], add(dp[v][0], dp[v][1])));
		dp[u][1] = add(mult(dp[u][0], dp[v][1]), mult(dp[u][1], dp[v][0]));
		dp[u][0] = mult(dp[u][0], dp[v][0]);
	}
	/*
	eprintf("%lld %lld %lld\n", dp[0][0], dp[0][1], dp[0][2]);
	eprintf("%lld %lld %lld\n", dp[1][0], dp[1][1], dp[1][2]);
	*/
	printf("%lld\n", add(dp[0][0], dp[0][2]));

	return 0;
}