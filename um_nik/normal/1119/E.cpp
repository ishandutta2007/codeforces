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

const ll INF = (ll)1e17;
const int N = 300300;
int n;
ll a[N];

bool solve(ll W) {
	ll cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll x = a[i];
		if ((x & 1) && cur) {
			x--;
			cur--;
		}
		ll y = min(x / 2, W);
		x -= 2 * y;
		W -= y;
		cur += y;
		cur = max(0LL, cur - x);
	}
	return W == 0 && cur == 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll l = 0, r = INF;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	printf("%lld\n", l);

	return 0;
}