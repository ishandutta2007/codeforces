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

const int N = 505;
int n;
int a[N];
int dp1[N][N];
int dp2[N][N];

void solve() {
	scanf("%d", &n);
	n++;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool ok = true;
	for (int i = 2; i < n; i++)
		ok &= a[i] >= a[i - 1];
	if (ok) {
		printf("0\n");
		return;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp1[i][j] = dp2[i][j] = N;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[0] && (i == 1 || a[0] >= a[i - 1])) {
			dp2[i + 1][0] = 1;
		}
		if (i > 1 && a[i - 1] > a[i]) break;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i - 1; j++) {
			if (a[i - 1] <= a[i]) {
				dp1[i + 1][j] = min(dp1[i + 1][j], dp1[i][j]);
			}
			if (a[i] > a[j] && a[i - 1] <= a[j]) {
				dp2[i + 1][j] = min(dp2[i + 1][j], dp1[i][j] + 1);
			}
		}
		for (int h = 0; h < i - 1; h++) {
			if (a[h] <= a[i]) {
				dp1[i + 1][i - 1] = min(dp1[i + 1][i - 1], dp2[i][h]);
			}
			if (a[i] > a[i - 1] && a[h] <= a[i - 1]) {
				dp2[i + 1][i - 1] = min(dp2[i + 1][i - 1], dp2[i][h] + 1);
			}
		}
	}
	int ans = N;
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp1[n][i]);
		ans = min(ans, dp2[n][i]);
	}
	if (ans == N)
		printf("-1\n");
	else
		printf("%d\n", ans);
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