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

const int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 100100;
const int K = 101;
int dp[N][K];
int a[N];
int n, k, m;
int pwk[N];
int pref[N];
pii lst[N][2];
int sumdp[N];

bool canPut(int x, int l, int r) {
	for (int i = 0; i < 2; i++) {
		if (lst[r][i].second != x && lst[r][i].first >= l)
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != -1) a[i]--;
	}
	if (m == 1) {
		printf("0\n");
		return 0;
	}
	pwk[0] = 1;
	for (int i = 1; i < N; i++)
		pwk[i] = mult(pwk[i - 1], k);
	
	lst[0][0] = lst[0][1] = mp(-1, -1);
	for (int i = 0; i < n; i++) {
		lst[i + 1][0] = lst[i][0];
		lst[i + 1][1] = lst[i][1];
		if (a[i] == -1) continue;
		if (lst[i + 1][0].second == a[i]) {
			lst[i + 1][0].first = i;
		} else {
			lst[i + 1][1] = lst[i + 1][0];
			lst[i + 1][0] = mp(i, a[i]);
		}
	}
	sumdp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < k; x++) {
			if (a[i] != -1 && a[i] != x) continue;
			dp[i + 1][x] = sumdp[i];
			if (i + 1 >= m && canPut(x, i + 1 - m, i + 1))
				dp[i + 1][x] = sub(dp[i + 1][x], sub(sumdp[i + 1 - m], dp[i + 1 - m][x]));
			sumdp[i + 1] = add(sumdp[i + 1], dp[i + 1][x]);
		}
		//printf("%d\n", sumdp[i]);
	}
	printf("%d\n", sumdp[n]);

	return 0;
}