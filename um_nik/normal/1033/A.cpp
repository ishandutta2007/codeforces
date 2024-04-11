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

int sgn(int x) {
	if (x == 0) return 0;
	return (x > 0 ? 1 : -1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	int ax, ay, bx, by, cx, cy;

	cin >> n;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;

	if (sgn(bx - ax) == sgn(cx - ax) && sgn(by - ay) == sgn(cy - ay))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}