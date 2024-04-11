#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

ll n;

ll go(ll x) {
	if (x == 0) {
		return 0;
	}

	ll l = 1, r = (ll)1e5;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		if (m * m * m <= x) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	return go(x - l * l * l) + 1;
}

void write(ll x) {
	if (x == 0) {
		return;
	}

	ll l = 1, r = (ll)1e5;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		if (m * m * m <= x) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	write(x - l * l * l);
	cout << l << endl;
}

int main() {
	cin >> n;

	ll x = 0;
	ll now = 1;

	vector <ll> v;

	while (true) {
		if (x + now * now * now > n) {
			break;
		}

		if (x + now * now * now >= (now + 1) * (now + 1) * (now + 1)) {
			now++;
			continue;
		}

		x += now * now * now;
		v.push_back(now);
	}
	
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		while (go(x - v[i] * v[i] * v[i] + (v[i] + 1) * (v[i] + 1) * (v[i] + 1)) == (int)v.size() && x - v[i] * v[i] * v[i] + (v[i] + 1) * (v[i] + 1) * (v[i] + 1) <= n) {
			x = x - v[i] * v[i] * v[i] + (v[i] + 1) * (v[i] + 1) * (v[i] + 1);
			v[i]++;
		}
	}

	for (int i = 0; i < (int)v.size(); i++) {
		//cout << v[i] << endl;
	}

	ll res = 0;
	ll ans = 0;

	for (ll i = n; i >= max((ll)1, n - 100000); i--) {
		ll g = go(i);

		if (g > res) {
			res = g;
			ans = i;
		}
	}

	//cout << res << ' ' << ans << endl;
	cout << go(x) << ' ' << x << endl;

	return 0;
}