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

const int N = 200200;
char s[N];
int n;
int ans;

int getPhi(int x) {
	int res = x;
	for (int y = 2; y * y <= x; y++) {
		if (x % y) continue;
		res /= y;
		res *= y - 1;
		while(x % y == 0) x /= y;
	}
	if (x > 1) {
		res /= x;
		res *= x - 1;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s", &n, s);
	for (int k = 1; k <= n; k++) {
		if (n % k) continue;
		bool ok = true;
		for (int r = 0; ok && r < k; r++) {
			int x = 0;
			for (int i = r; i < n; i += k)
				x ^= (int)(s[i] - '0');
			ok &= x == 0;
		}
		if (ok) ans += getPhi(n / k);
	}
	printf("%d\n", ans);

	return 0;
}