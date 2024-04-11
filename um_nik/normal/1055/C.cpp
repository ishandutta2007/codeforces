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

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

ll solve(ll l1, ll r1, ll t1, ll l2, ll r2, ll t2) {
	r1 -= l1;
	r2 -= l2;
	l2 += l1 * t2;
	l2 -= l1;
	l2 %= t2;
	ll g = gcd(t1, t2);
	l2 %= g;
	ll L = l2, R = min(r1, l2 + r2);
	return max(0LL, R - L);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll l1, r1, t1, l2, r2, t2;
	cin >> l1 >> r1 >> t1;
	cin >> l2 >> r2 >> t2;

	r1++;
	r2++;

	cout << max(solve(l1, r1, t1, l2, r2, t2), solve(l2, r2, t2, l1, r1, t1)) << endl;

	return 0;
}