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

char s[] = "aeiou";

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d", &k);
	for (int n = 5; n <= k; n++) {
		if (k % n) continue;
		int m = k / n;
		if (m < 5) break;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++) {
				printf("%c", s[(x + y) % 5]);
			}
		printf("\n");
		return 0;
	}
	printf("-1\n");

	return 0;
}