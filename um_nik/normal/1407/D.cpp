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

const int LOG = 19;
const int N = 300300;
int n;
vector<int> g[N];
int a[N];
int sparseMax[LOG][N], sparseMin[LOG][N];
int p2[N];
int dp[N];

int getMax(int l, int r) {
	int k = p2[r - l];
	return max(sparseMax[k][l], sparseMax[k][r - (1 << k)]);
}
int getMin(int l, int r) {
	int k = p2[r - l];
	return min(sparseMin[k][l], sparseMin[k][r - (1 << k)]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 2; i <= n; i++)
		p2[i] = p2[i / 2] + 1;
	for (int i = 0; i < n; i++)
		sparseMin[0][i] = sparseMax[0][i] = a[i];
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= n; i++) {
			sparseMax[k + 1][i] = max(sparseMax[k][i], sparseMax[k][i + (1 << k)]);
			sparseMin[k + 1][i] = min(sparseMin[k][i], sparseMin[k][i + (1 << k)]);	
		}

	for (int i = 0; i < n - 1; i++)
		g[i].push_back(i + 1);
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) continue;
		if (a[i] < a[i + 1]) {
			int l = i + 2, r = n + 1;
			while(r - l > 1) {
				int x = (l + r) / 2;
				if (getMin(i + 1, x) <= a[i])
					r = x;
				else
					l = x;
			}
			if (r <= n)
				g[i].push_back(r - 1);
		} else {
			int l = i + 2, r = n + 1;
			while(r - l > 1) {
				int x = (l + r) / 2;
				if (getMax(i + 1, x) >= a[i])
					r = x;
				else
					l = x;
			}
			if (r <= n)
				g[i].push_back(r - 1);
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i - 1] == a[i]) continue;
		if (a[i - 1] > a[i]) {
			int l = -1, r = i - 1;
			while(r - l > 1) {
				int x = (l + r) / 2;
				if (getMin(x, i) <= a[i])
					l = x;
				else
					r = x;
			}
			if (l >= 0)
				g[l].push_back(i);
		} else {
			int l = -1, r = i - 1;
			while(r - l > 1) {
				int x = (l + r) / 2;
				if (getMax(x, i) >= a[i])
					l = x;
				else
					r = x;
			}
			if (l >= 0)
				g[l].push_back(i);
		}
	}

	for (int i = 0; i < n; i++)
		dp[i] = N;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int x : g[i])
			dp[x] = min(dp[x], dp[i] + 1);
	printf("%d\n", dp[n - 1]);

	return 0;
}