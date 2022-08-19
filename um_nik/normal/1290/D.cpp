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

const int N = 1027;
bool ans[N];
int n, k;

void restart() {
	printf("R\n");
	fflush(stdout);
}
bool query(int x) {
	printf("? %d\n", x + 1);
	fflush(stdout);
	char t;
	scanf(" %c", &t);
	return t == 'Y';
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);

	if (k == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				restart();
				if (query(i)) throw;
				ans[j] |= query(j);
			}
		}
	} else {
		for (int d = 1; d < (2 * n) / k; d++) {
			for (int r = 0; r < d; r++) {
				if (r + d >= (2 * n) / k) continue;
				restart();
				for (int i = r; i < (2 * n) / k; i += d) {
					for (int j = 0; j < k / 2; j++) {
						ans[i * (k / 2) + j] |= query(i * (k / 2) + j);
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res += !ans[i];
	printf("! %d\n", res);
	fflush(stdout);
	return 0;
}