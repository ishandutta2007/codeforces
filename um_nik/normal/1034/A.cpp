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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int L = 100;
const int C = 15000100;
int d[C];
int ans[C][3];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 2; x < C; x++) {
		if (d[x] != 0) continue;
		ans[x][0] = L;
		for (int y = x; y < C; y += x)
			if (d[y] == 0)
				d[y] = x;
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		while(x > 1) {
			int p = d[x];
			ans[p][2]++;
			int k = 0;
			while(x % p == 0) {
				x /= p;
				k++;
			}
			if (k < ans[p][0]) {
				ans[p][0] = k;
				ans[p][1] = 0;
			}
			if (k == ans[p][0])
				ans[p][1]++;
		}
	}
	int res = n;
	for (int x = 2; x < C; x++) {
		if (d[x] != x) continue;
		if (ans[x][0] == L) continue;
		if (ans[x][2] != n) {
			res = min(res, n - ans[x][2]);
			continue;
		}
		res = min(res, ans[x][1]);
	}
	if (res == n) res = -1;
	printf("%d\n", res);

	return 0;
}