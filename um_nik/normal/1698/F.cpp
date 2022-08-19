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
int n;
int a[N], b[N];
int c[N][N];
int ans[N][2];
int ansSz;

void myRev(int l, int r) {
	ans[ansSz][0] = l;
	ans[ansSz][1] = r;
	ansSz++;
	reverse(b + l, b + r + 1);
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		printf("NO\n");
		return;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			c[i][j] = 0;
	for (int i = 1; i < n; i++) {
		int x = a[i - 1], y = a[i];
		if (x > y) swap(x, y);
		c[x][y]++;
	}
	for (int i = 1; i < n; i++) {
		int x = b[i - 1], y = b[i];
		if (x > y) swap(x, y);
		c[x][y]--;
		if (c[x][y] < 0) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	ansSz = 0;
	for (int p = 0; p < n; p++) if (a[p] != b[p]) {
		assert(0 < p && p < n - 1);
		bool ok = false;
		for (int i = p; !ok && i + 1 < n; i++) {
			if (b[i] == a[p] && b[i + 1] == a[p - 1]) {
				myRev(p - 1, i + 1);
				ok = true;
			}
		}
		if (ok) continue;
		int q = p;
		while(q < n - 1 && (b[q] != a[p - 1] || b[q + 1] != a[p])) q++;
		assert(q < n - 1);
		bool fnd = false;
		for (int i = p; !fnd && i <= q; i++)
			for (int j = q + 1; !fnd && j < n; j++)
				if (b[i] == b[j]) {
					fnd = true;
					myRev(i, j);
				}
		for (int i = p; !ok && i + 1 < n; i++) {
			if (b[i] == a[p] && b[i + 1] == a[p - 1]) {
				myRev(p - 1, i + 1);
				ok = true;
			}
		}
		assert(ok);
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
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