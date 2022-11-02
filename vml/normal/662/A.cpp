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

const int maxn = (int)5e5 + 10;

ll v[maxn];
int g[1 << 16];

int getbit(int x) {
	if (x == 0) {
		return -1;
	}

	int pos = 0;

	while ((x & 1) == 0) {
		x >>= 1;
		pos++;
	}

	return pos;
}

int mask = (1 << 16) - 1;

int get(ll x) {
	if (x == 0) {
		return -1;
	}

	if (g[mask & x] != -1) {
		return g[mask & x];
	}

	x >>= 16;

	if (g[mask & x] != -1) {
		return 16 + g[mask & x];
	}

	x >>= 16;

	if (g[mask & x] != -1) {
		return 32 + g[mask & x];
	}

	x >>= 16;

	return 48 + g[mask & x];
}

int main() {
	int n;

	cin >> n;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ll a, b;

		scanf("%I64d %I64d", &a, &b);

		ans ^= a;

		v[i] = a ^ b;
	}

	for (int i = 0; i < (1 << 16); i++) {
		g[i] = getbit(i);
	}

	vector <ll> now;

	for (int j = 0; j <= 63; j++) {
		bool st = false;

		for (int i = 0; i < n; i++) {
			if (get(v[i]) == j) {
				now.push_back(v[i]);
				st = true;
				break;
			}
		}

		if (!st) {
			continue;
		}

		for (int i = 0; i < n; i++) {
			if (get(v[i]) == j) {
				v[i] ^= now.back();
			}
		}
	}

	for (int i = 0; i < (int)now.size(); i++) {
		if (get(now[i]) == get(ans)) {
			ans ^= now[i];
		}
	}

	if (ans != 0) {
		cout << "1/1" << endl;
	} else if (now.empty()) {
		cout << "0/1" << endl;
	} else {
		cout << ((ll)1 << now.size()) - 1 << '/' << ((ll)1 << now.size()) << endl;
	}

	return 0;
}