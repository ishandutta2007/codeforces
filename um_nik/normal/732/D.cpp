#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 100100;
int m;
int a[N];
int b[N];
int c[N];
pii e[N];

bool solve(int n) {
	for (int i = 0; i < m; i++)
		c[i] = n;
	for (int i = 0; i < n; i++)
		if (a[i] != -1)
			c[a[i]] = i;
	for (int i = 0; i < m; i++) {
		if (c[i] == n)
			return false;
		e[i] = mp(c[i], b[i]);
	}
	sort(e, e + m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += e[i].second;
		if (sum > e[i].first) return false;
		sum++;
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (r == n + 1)
		printf("-1\n");
	else
		printf("%d\n", r);

	return 0;
}