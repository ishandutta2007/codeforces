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


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1) {
		printf("0\n");
		return 0;
	}
	if (n <= m) {
		for (int i = 1; i <= n; i++) {
			for (int j = n + 1; j <= n + m; j++) {
				printf("%d ", i * j);
			}
			printf("\n");
		}
	} else {
		for (int i = m + 1; i <= m + n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d ", i * j);
			}
			printf("\n");
		}
	}

	return 0;
}