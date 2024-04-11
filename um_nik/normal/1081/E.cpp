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
int n;
ll a[N];

ll mySqrt(ll x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	ll y = (ll)sqrt(x) - 2;
	if (y < 0) y = 0;
	while(y * y < x) y++;
	if (y * y == x) return y;
	return -1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i += 2)
		scanf("%lld", &a[i]);
	ll x = 0;
	for (int i = 1; i < n; i += 2) {
		ll y = x + 1;
		bool ok = false;
		while(y <= a[i]) {
			ll z = mySqrt(y * y - a[i]);
			if (z <= x) {
				y++;
				continue;
			}
			a[i - 1] = z * z - x * x;
			x = y;
			ok = true;
			break;
		}
		if (!ok) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}