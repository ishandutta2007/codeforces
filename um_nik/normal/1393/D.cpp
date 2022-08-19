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

const int N = 2002;
int n, m;
char s[N][N];
int a[N][N];
char t[N][N];
int b[N][N];

void solve() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || s[i][j] != s[i - 1][j] || s[i][j] != s[i][j - 1]) {
				a[i][j] = 1;
				continue;
			}
			a[i][j] = 1 + min(a[i - 1][j], a[i][j - 1]);
		}
}

void myRot(int &x, int &y, int n, int m, int p) {
	while(p--) {
		int xx = m - 1 - y, yy = x;
		x = xx;
		y = yy;
		swap(n, m);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = N;

	for (int it = 0; it < 4; it++) {
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				t[x][y] = s[x][y];
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				int xx = m - 1 - y, yy = x;
				s[xx][yy] = t[x][y];
			}
		swap(n, m);
		solve();
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				int xx = x, yy = y;
				myRot(xx, yy, n, m, 3 - it);
				b[xx][yy] = min(b[xx][yy], a[x][y]);
			}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += b[i][j];
	printf("%lld\n", ans);

	return 0;
}