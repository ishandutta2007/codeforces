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
int n, m;
int a[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i][0] = N;
		a[i][1] = -1;
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		x--;
		if (a[x][1] == -1)
			a[x][0] = i;
		a[x][1] = i;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][1] == -1) ans++;
	}
	for (int i = 1; i < n; i++) {
		if (a[i][0] > a[i - 1][1]) ans++;
		if (a[i - 1][0] > a[i][1]) ans++;
	}
	printf("%d\n", ans);

	return 0;
}