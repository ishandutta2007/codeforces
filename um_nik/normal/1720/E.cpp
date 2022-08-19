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

const int N = 505;
const int M = N * N;
int n, k;
int a[N][N];
int b[M][4];
int p[N][N];

void solve(int len) {
	for (int i = 0; i <= n - len; i++)
		for (int j = 0; j <= n - len; j++)
			p[i][j] = 0;
	for (int i = 0; i < n * n; i++) if (b[i][1] != -1) {
		int x1 = max(0, b[i][1] - len + 1);
		int x2 = b[i][0] + 1;
		int y1 = max(0, b[i][3] - len + 1);
		int y2 = b[i][2] + 1;
		if (x1 >= x2 || y1 >= y2) continue;
		p[x1][y1]++;
		p[x2][y1]--;
		p[x1][y2]--;
		p[x2][y2]++;
	}
	for (int i = 0; i <= n - len; i++)
		for (int j = 0; j <= n - len; j++) {
			if (i > 0) p[i][j] += p[i - 1][j];
			if (j > 0) p[i][j] += p[i][j - 1];
			if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
			if (p[i][j] == k || p[i][j] == k + 1) {
				printf("1\n");
				exit(0);
			}
		}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int c = 0; c < n * n; c++) {
		b[c][0] = b[c][2] = n + 1;
		b[c][1] = b[c][3] = -1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
			int c = a[i][j];
			b[c][0] = min(b[c][0], i);
			b[c][1] = max(b[c][1], i);
			b[c][2] = min(b[c][2], j);
			b[c][3] = max(b[c][3], j);
		}
	for (int i = 0; i < n * n; i++) if (b[i][1] != -1) {
		k--;
	}
	if (k >= 0) {
		printf("%d\n", k);
		return 0;
	}
	k *= -1;
	for (int len = 1; len <= n; len++)
		solve(len);
	printf("2\n");

	return 0;
}