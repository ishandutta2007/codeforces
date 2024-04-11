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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int mySqrt(int x) {
	int y = max(0, (int)sqrt(x) - 5);
	while(y * y < x) y++;
	if (y * y != x) return -1;
	return y;
}

const int N = 1100;
int n;
int b[N][N];
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
	int g = 0;
	for (int i = 1; i < n; i++)
		g = gcd(g, b[0][i]);
	a[0] = g;
	for (int i = 1; i < n; i++)
		a[i] = b[0][i] / a[0];
	g = a[1] * a[2];
	if (b[1][2] % g) throw;
	g = b[1][2] / g;
	g = mySqrt(g);
	if (g == -1) throw;
	a[0] /= g;
	for (int i = 1; i < n; i++)
		a[i] *= g;
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}