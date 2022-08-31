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

const int N = 100100;
int a[2][N];
int n, q;
int cnt;

void change(int x, int y) {
	for (int z = y - 1; z <= y + 1; z++) {
		if (z < 0 || z >= n) continue;
		cnt -= a[x][y] & a[x ^ 1][z];
	}
	a[x][y] ^= 1;
	for (int z = y - 1; z <= y + 1; z++) {
		if (z < 0 || z >= n) continue;
		cnt += a[x][y] & a[x ^ 1][z];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		change(x, y);
		if (cnt == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}