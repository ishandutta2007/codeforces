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

const int N = 3030;
int n, k;
vector<ll> a[N];
ll b[N][2];
ll dp[N][N];
int m;
ll ans;

void addDp(int L, int R) {
	for (int i = L; i < R; i++) {
		for (int x = 0; x <= k; x++) {
			dp[m + 1][x] = dp[m][x];
			if (x >= b[i][0])
				dp[m + 1][x] = max(dp[m + 1][x], dp[m][x - b[i][0]] + b[i][1]);
		}
		m++;
	}
}

void solve(int L, int R) {
	if (L + 1 == R) {
		ll cur = 0;
		for (int i = 0; i <= k && i <= (int)a[L].size(); i++) {
			ans = max(ans, cur + dp[m][k - i]);
			if (i < (int)a[L].size()) cur += a[L][i];
		}
		return;
	}
	int oldm = m;
	int M = (L + R) / 2;
	addDp(M, R);
	solve(L, M);
	m = oldm;
	addDp(L, M);
	solve(M, R);
	m = oldm;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int sz;
		scanf("%d", &sz);
		b[i][0] = sz;
		b[i][1] = 0;
		a[i] = vector<ll>(sz);
		for (int j = 0; j < sz; j++) {
			scanf("%lld", &a[i][j]);
			b[i][1] += a[i][j];
		}
	}
	m = 0;
	solve(0, n);
	printf("%lld\n", ans);

	return 0;
}