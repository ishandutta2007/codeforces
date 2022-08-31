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

int Q = 0;
int P;
int n, k;
const int MAG = 300;
const int N = 1010;
int a[N][2 * N + 1];


int query(int x) {
	printf("? %d\n", x + 1);
	fflush(stdout);
#ifdef LOCAL
	int val = -1;
	x = (x + n - P) % n;
	if (n < MAG) {
		val = a[Q][x];
	} else {
		if (x >= N) x -= n;
		if (abs(x) >= N)
			val = k;
		else
			val = a[Q][N + x];
	}
	Q++;
	return val;
#endif
	scanf("%d", &x);
	return x;
}

void solveSmall() {
	eprintf("solveSmall %d %d\n", n, k);
	for (int i = 0; i < n; i++)
		a[0][i] = k;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < n; j++) {
			int x = (a[i - 1][(j + n - 1) % n] + 1) / 2;
			int y = (a[i - 1][(j + 1) % n]) / 2;
			if (j == 1) x = a[i - 1][0];
			if (j == n - 1) y = 0;
			a[i][j] = x + y;
		}
	}
	eprintf("precalced\n");
	vector<pii> b;
	for (int i = 0; i < 900; i++) {
		int p = myRand(n);
		b.push_back(mp(p, query(p)));
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < 900; j++) {
			int p = b[j].first;
			p = (p + n - i) % n;
			ok &= a[j][p] == b[j].second;
		}
		if (ok) ans.push_back(i + 1);
	}
	assert((int)ans.size() == 1);
	printf("! %d\n", ans[0]);
	fflush(stdout);
	exit(0);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	eprintf("n = %d, k = %d\n", n, k);
#ifdef LOCAL
	scanf("%d", &P);
#endif
	if (n < MAG) {
		solveSmall();
	}

	for (int i = 0; i <= 2 * N; i++)
		a[0][i] = k;
	for (int i = 1; i < N; i++) {
		a[i][0] = a[i][2 * N] = k;
		for (int j = 1; j < 2 * N; j++) {
			int x = (a[i - 1][j - 1] + 1) / 2;
			int y = (a[i - 1][j + 1]) / 2;
			if (j == N + 1) x = a[i - 1][N];
			if (j == N - 1) y = 0;
			a[i][j] = x + y;
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = N - 20; j <= N + 20; j++)
			eprintf("%d ", a[i][j]);
		eprintf("\n");
	}

	int st = 0;
	int d = 0;
	while(true) {
		if (query((st + d) % n) > k) {
			break;
		}
		st += d;
		d++;
	}
	while(true) {
		if (query(st) == k) {
			printf("! %d\n", st + 1);
			fflush(stdout);
			return 0;
		}
		st = (st + 1) % n;
	}

	return 0;
}