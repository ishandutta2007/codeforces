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

const int N = 3003;
int n, m;
int a[N];
bool used[N];
pii b[N];
int c[N];
int all;

bool movePair() {
	for (int i = 0; i < 2 * n; i++) {
		if (used[i]) continue;
		if (c[i] == -1) continue;
		int v = i;
		if (a[v] < a[c[v]]) v = c[v];
		printf("%d\n", v + 1);
		fflush(stdout);
		used[v] = 1;
		all--;
		int x;
		scanf("%d", &x);
		x--;
		all--;
		used[x] = 1;
		if (c[v] != x) throw;
		return true;
	}
	return false;
}

void readMove() {
	int v;
	scanf("%d", &v);
	v--;
	all--;
	if (c[v] != -1) throw;
	if (used[v]) throw;
	used[v] = 1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 2 * n; i++)
		c[i] = -1;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		c[x] = y;
		c[y] = x;
	}
	int k = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (c[i] != -1) continue;
		b[k++] = mp(a[i], i);
	}
	sort(b, b + k);
	reverse(b, b + k);

	all = 2 * n;

	int t;
	scanf("%d", &t);

	all = 2 * n;

	if (t == 2) {
		int v;
		while(all > 0) {
			scanf("%d", &v);
			all--;
			v--;
			used[v] = 1;
			if (c[v] == -1) break;
			v = c[v];
			used[v] = 1;
			printf("%d\n", v + 1);
			fflush(stdout);
			all--;
		}
	}
	while(all > 1) {
		if (movePair()) continue;
		for (int i = 0; i < k; i++) {
			int v = b[i].second;
			if (used[v]) continue;
			printf("%d\n", v + 1);
			fflush(stdout);
			used[v] = 1;
			all--;
			readMove();
			break;
		}
	}
	if (all == 1) {
		for (int i = 0; i < 2 * n; i++)
			if (!used[i]) {
				printf("%d\n", i + 1);
				fflush(stdout);
			}
	}

	return 0;
}