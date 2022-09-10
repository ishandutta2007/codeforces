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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 2020;
int n;
char s[N];
int dp[N][N];

int getRes2(char c1, char c2, int l, int r) {
	if (dp[l][r] != 0) return dp[l][r];
	if (c1 < c2) return 1;
	if (c1 > c2) return -1;
	return 0;
}
int getRes(char c, int l, int r) {
	return min(getRes2(c, s[l], l + 1, r), getRes2(c, s[r - 1], l, r - 1));
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i <= n; i++)
		dp[i][i] = 0;
	for (int len = 2; len <= n; len += 2)
		for (int l = 0; l + len <= n; l++) {
			int r = l + len;
			dp[l][r] = -1;
			dp[l][r] = max(dp[l][r], getRes(s[l], l + 1, r));
			dp[l][r] = max(dp[l][r], getRes(s[r - 1], l, r - 1));
		}
	if (dp[0][n] == 1) {
		printf("Alice\n");
	} else if (dp[0][n] == 0) {
		printf("Draw\n");
	} else {
		printf("Bob\n");
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}