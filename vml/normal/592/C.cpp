#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <ctime>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <bitset>
#define ll long long
 
using namespace std;

const ll inf = (ll)6e18;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	ll g = gcd(a, b);

	a /= g;

	if (a > inf / b) {
		return -1;
	}

	return a * b;
}

ll go(ll a, ll b, ll l) {
	if (a / l == b / l) {
		return (a / l + 1) * (b - a + 1);
	}

	ll b1 = (b / l) * l;
	b1--;

	ll ans = (b / l + 1) * (b - b1);
	ll a1 = (a / l + 1) * l;

	ans += (a / l + 1) * (a1 - a);

	if (a1 <= b1) {
		ll lef = a1 / l + 1;
		ll rig = b1 / l + 1;

		ans += l * lef * (rig - lef + 1);
		rig -= lef;
		lef = 0;
		ans += l * rig * (rig + 1) / 2;
	}

	return ans;
}

int main() {
	ll t, a, b;

	cin >> t >> a >> b;

	if (a > b) {
		swap(a, b);
	}

	ll l = lcm(a, b);

	if (l == -1) {
		l = inf;
	}

	ll ans = 0;

	if (t < a) {
		cout << "1/1" << endl;
	} else {
		ll f = go(t - a + 1, t, l);
		f--;

		ll h = gcd(f, t);

		cout << f / h << '/' << t / h << endl;
	}

	return 0;
}