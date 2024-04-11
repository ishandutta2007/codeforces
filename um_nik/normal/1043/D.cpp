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

const int N = 100100;
int g[N];
bool st[N];
ll ans;
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		g[i] = -1;
	while(m--) {
		int x;
		scanf("%d", &x);
		x--;
		for (int i = 1; i < n; i++) {
			int y;
			scanf("%d", &y);
			y--;
			if (g[x] == -1)
				g[x] = y;
			if (g[x] != y)
				g[x] = -2;
			x = y;
		}
		g[x] = -2;
	}
	for (int i = 0; i < n; i++)
		st[i] = 1;
	for (int i = 0; i < n; i++)
		if (g[i] != -2)
			st[g[i]] = 0;
	for (int i = 0; i < n; i++) {
		if (!st[i]) continue;
		ll len = 0;
		int v = i;
		while(v != -2) {
			len++;
			v = g[v];
		}
		ans += len * (len + 1) / 2;
	}
	printf("%lld\n", ans);

	return 0;
}