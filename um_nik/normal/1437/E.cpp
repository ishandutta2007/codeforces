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

const int INF = (int)1e9 + (int)1e8;
const int N = 500500;
int a[N];
int c[N];
int n;

int solve(int L, int R) {
	/*
	eprintf("solve\n");
	for (int i = L; i <= R; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	*/
	if (a[L] > a[R]) return N;
	int len = R - L;
	for (int i = 0; i < len; i++)
		c[i] = INF;
	c[0] = 0;
	for (int i = L + 1; i < R; i++) {
		if (a[i] < a[L] || a[i] > a[R]) continue;
		int p = upper_bound(c, c + len, a[i]) - c;
		c[p] = a[i];
	}
	int ans = len - 1;
	while(c[ans] == INF) ans--;
	return len - 1 - ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += n - i;
	}
	a[0] = 0;
	a[n + 1] = INF - 2;
	n += 2;
	int ans = 0;
	int lst = 0;
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		ans += solve(lst, x);
		if (ans >= N) {
			printf("-1\n");
			return 0;
		}
		lst = x;
	}
	ans += solve(lst, n - 1);
	if (ans >= N) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}