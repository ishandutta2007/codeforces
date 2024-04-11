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

const int N = 52;
const int M = 22;
const int K = (1 << 20) + 5;
int n, m;
char s[N][M];
ll a[K];
int C[M][M];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < M; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < M; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	m = strlen(s[0]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int mask = 0;
			for (int h = 0; h < m; h++)
				if (s[i][h] == s[j][h])
					mask |= 1 << h;
			a[mask] |= 1LL << i;
			a[mask] |= 1LL << j;
		}
	for (int mask = (1 << m) - 1; mask > 0; mask--)
		for (int i = 0; i < m; i++)
			if ((mask >> i) & 1)
				a[mask ^ (1 << i)] |= a[mask];
	double ans = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		int p = 0, q = 0;
		for (int i = 0; i < m; i++)
			if ((mask >> i) & 1)
				p++;
		for (int i = 0; i < n; i++)
			if ((a[mask] >> i) & 1)
				q++;
		ans += (double)q / C[m][p];
	}
	ans /= n;
	printf("%.13lf\n", ans);

	return 0;
}