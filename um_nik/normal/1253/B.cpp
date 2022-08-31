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

const int N = 1000100;
int a[N];
int ans[N];
int ansSz;
int t;
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ans[ansSz++] = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0) {
			if (a[x] > t) {
				printf("-1\n");
				return 0;
			}
			a[x] = t + 1;
			m++;
		} else {
			x *= -1;
			if (a[x] != t + 1) {
				printf("-1\n");
				return 0;
			}
			a[x] = t + 2;
			m--;
		}
		if (m == 0) {
			t += 3;
			ans[ansSz++] = i + 1;
		}
	}
	if (m == 0) {
		printf("%d\n", ansSz - 1);
		for (int i = 1; i < ansSz; i++)
			printf("%d ", ans[i] - ans[i - 1]);
		printf("\n");
	} else
		printf("-1\n");

	return 0;
}