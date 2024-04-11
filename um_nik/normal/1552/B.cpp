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

const int N = 50500;
int n;
int a[N][5];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);
	}
	int v = 0;
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++)
			cnt += (int)(a[i][j] < a[v][j]);
		if (cnt >= 3) v = i;
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (i == v) continue;
		int cnt = 0;
		for (int j = 0; j < 5; j++)
			cnt += (int)(a[v][j] < a[i][j]);
		ok &= cnt >= 3;
	}
	if (ok)
		printf("%d\n", v + 1);
	else
		printf("-1\n");
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