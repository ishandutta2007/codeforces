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

const int N = 500100;
int n, m;
int deg[N];
int a[N];

bool solve(int k) {
	int lft = k - m;
	for (int i = 0; i < m; i++)
		lft -= max(0, a[i] + i - k);
	return lft >= 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		deg[i] = 0;
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		deg[x]++;
	}
	m = 0;
	for (int i = 0; i <= n; i++)
		if (deg[i] > 0)
			a[m++] = deg[i];
	a[m++] = 1;
	sort(a, a + m);
	reverse(a, a + m);
	for (int i = 0; i < m; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	int l = m - 1, r = n;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);
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