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

const int C = 111;
int a[C][2];
int n;

bool solve(int id) {
	int minX = C, maxX = 0, minY = C, maxY = 0;
	for (int i = 0; i <= 4 * n; i++) {
		if (i == id) continue;
		minX = min(minX, a[i][0]);
		maxX = max(maxX, a[i][0]);
		minY = min(minY, a[i][1]);
		maxY = max(maxY, a[i][1]);
	}
	if (maxX - minX != maxY - minY) return false;
	for (int i = 0; i <= 4 * n; i++) {
		if (i == id) continue;
		if (a[i][0] != minX && a[i][0] != maxX && a[i][1] != minY && a[i][1] != maxY)
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i <= 4 * n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i <= 4 * n; i++) {
		if (solve(i)) {
			printf("%d %d", a[i][0], a[i][1]);
			return 0;
		}
	}
	throw;
	return 0;
}