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

	ll x;
	scanf("%lld", &x);
	ll p = -1;
	for (ll y = 2; y * y <= x; y++)
		if (x % y == 0) {
			p = y;
			break;
		}
	if (p == -1) {
		printf("%lld\n", x);
		return 0;
	}
	while(x % p == 0) x /= p;
	if (x == 1)
		printf("%lld\n", p);
	else
		printf("1\n");

	return 0;
}