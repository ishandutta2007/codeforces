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

const int INF = (int)2e9 + 1;
const int B = 9;
const int M = (1 << B) + 3;
int a[M];
pii b[M][2];
pii bst = mp(0, -INF);
int ans1 = -1, ans2 = -1;

int readMask() {
	int mask = 0;
	int z;
	scanf("%d", &z);
	int x;
	while(z--) {
		scanf("%d", &x);
		x--;
		mask |= 1 << x;
	}
	return mask;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	while(n--) {
		int mask = readMask();
		a[mask]++;
	}
	for (int mask = 0; mask < (1 << B); mask++)
		for (int i = 0; i < 2; i++)
			b[mask][i] = mp(INF, -1);
	for (int i = 0; i < m; i++) {
		int mask, c;
		scanf("%d", &c);
		mask = readMask();
		pii t = mp(c, i);
		for (int j = 0; j < 2; j++) {
			if (t < b[mask][j])
				swap(t, b[mask][j]);
		}
	}
	for (int k = 0; k < B; k++)
		for (int mask = 0; mask < (1 << B); mask++) {
			if ((mask >> k) & 1) continue;
			a[mask ^ (1 << k)] += a[mask];
		}
	for (int m1 = 0; m1 < (1 << B); m1++)
		for (int m2 = 0; m2 < (1 << B); m2++)
			for (int t1 = 0; t1 < 2; t1++)
				for (int t2 = 0; t2 < 2; t2++) {
					if (m1 == m2 && t1 == t2) continue;
					if (b[m1][t1].second == -1) continue;
					if (b[m2][t2].second == -1) continue;
					//int x = a[m1] + a[m2] - a[m1 & m2];
					int x = a[m1 | m2];
					pii c = mp(x, -(b[m1][t1].first + b[m2][t2].first));
					if (c > bst) {
						bst = c;
						ans1 = b[m1][t1].second;
						ans2 = b[m2][t2].second;
					}
				}
	printf("%d %d\n", ans1 + 1, ans2 + 1);

	return 0;
}