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
ll a[N];
char s[N];
int n;
ll c0, e1, e2;
int cf = 5;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	scanf("%s", s);

	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			cf = 3;
			c0 += 2 * a[i];
			e1 += a[i];
			e2 += a[i];
		} else if (s[i] == 'G') {
			if (e1 >= a[i]) {
				c0 += 2 * a[i];
				e1 -= a[i];
				e2 += a[i];
			} else {
				c0 += 2 * e1 + (a[i] - e1) * 3;
				e1 = 0;
				e2 += a[i];
			}
		} else if (s[i] == 'L') {
			if (e1 >= a[i]) {
				c0 += 2 * a[i];
				e1 -= a[i];
				e2 -= a[i];
			} else if (e2 >= a[i]) {
				c0 += 2 * e1 + (a[i] - e1) * 3;
				e1 = 0;
				e2 -= a[i];
			} else {
				c0 += 2 * e1 + (e2 - e1) * 3 + (a[i] - e2) * (cf + 1);
				e1 = e2 = 0;
			}
		} else throw;
	}
	printf("%lld\n", c0);

	return 0;
}