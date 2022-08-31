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

const int N = 1010;
int a[N][N];
bool used[N][N];
int n, m;
int ans[N * N][3];
int ansSz;
int cc[10];

void check(int x, int y) {
	if (x < 0 || x + 1 >= n || y < 0 || y + 1 >= m) return;
	if (used[x][y]) return;
	int sz = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			int c = a[x + i][y + j];
			if (c != -1)
				cc[sz++] = c;
		}
	if (sz == 0) return;
	sort(cc, cc + sz);
	if (cc[0] != cc[sz - 1]) return;
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = cc[0];
	used[x][y] = 1;
	ansSz++;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			check(i, j);
	for (int i = 0; i < ansSz; i++) {
		int x = ans[i][0], y = ans[i][1];
		a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = -1;
		for (int j = -1; j <= 1; j++)
			for (int k = -1; k <= 1; k++)
				check(x + j, y + k);
	}
	bool ok = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ok &= a[i][j] == -1;
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ansSz);
	for (int i = ansSz - 1; i >= 0; i--)
		printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2]);

	return 0;
}