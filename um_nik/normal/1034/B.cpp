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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll n, m;
	cin >> n >> m;
	ll S = n * m;
	if (n > m) swap(n, m);

	if (n == 1) {
		ll ans = (m / 6) * 6;
		m %= 6;
		if (m >= 4) ans += 2;
		if (m >= 5) ans += 2;
		cout << ans << endl;
	} else if (n == 2) {
		if (m == 2)
			cout << S - 4 << endl;
		else if (m == 3)
			cout << S - 2 << endl;
		else if (m == 7)
			cout << S - 2 << endl;
		else
			cout << S << endl;
	} else
		cout << S - (S & 1) << endl;

	return 0;
}