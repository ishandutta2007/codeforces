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

const int N = 1010;
int n;
int a[N][2];
int ans[N];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	while(ansSz == 0) {
		for (int i = 0; i < n; i++) {
			if (abs(a[i][0] + a[i][1]) & 1)
				ans[ansSz++] = i;
		}
		if (ansSz != 0 && ansSz != n) {
			printf("%d\n", ansSz);
			for (int i = 0; i < ansSz; i++)
				printf("%d ", ans[i] + 1);
			printf("\n");
			return 0;
		}
		if (abs(a[0][0] + a[0][1]) & 1) {
			for (int i = 0; i < n; i++)
				a[i][1]++;
		}
		for (int i = 0; i < n; i++) {
			int x = a[i][0] + a[i][1];
			int y = a[i][0] - a[i][1];
			a[i][0] = x / 2;
			a[i][1] = y / 2;
		}
		ansSz = 0;
	}

	return 0;
}