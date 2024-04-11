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

char ans[] = "01101100";
int a[30][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	if (n < 8) {
		printf("%c\n", ans[n]);
		return 0;
	}
	a[0][0] = 0;
	a[0][1] = 1;
	for (int i = 0; i < 23; i++) {
//		eprintf("%d %d\n", a[i][0], a[i][1]);
		a[i + 1][0] = a[i + 1][1] = a[i][0] + a[i][1];
		if (a[i][0] & 1) a[i + 1][1]++;
	}
	int k = 0;
	while((1 << (k + 1)) <= n) k++;
	n -= (1 << k) - 1 + a[k - 1][0];
	if (n == 0 || n == 1)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}