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

ll c[maxn];
ll x[maxn];

ll stup(int n, ll k) {
	for (int i = 0; i < k; i++) {
		sort(c, c + n);
		c[n - 1]--;
		if (c[n - 1] < c[0]) {
			c[n - 1]++;
		} else {
			c[0]++;
		}
	}

	sort(c, c + n);

	for (int i = 0; i < n; i++) {
		cout << c[i] << ' ';
	}
	cout << endl;

	return c[n - 1] - c[0];
}

int main() {
	int n;
	ll k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &c[i]);
	}

	sort(c, c + n);

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += c[i];
	}

	ll o = sum % n;

	for (int i = 0; i < n; i++) {
		x[i] = sum / n;

		if (o != 0) {
			x[i]++;
			o--;
		}
	}

	sort(x, x + n);

	ll cnt = 0;

	for (int i = 0; i < n; i++) {
		if (x[i] >= c[i]) {
			cnt += x[i] - c[i];
		}
	}

	if (cnt <= k) {
		if (sum % n == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}

		return 0;
	}

	ll last = c[0];

	ll mins = -1;
	ll lk = k;

	for (int i = 1; i < n; i++) {
		if (last == c[i]) {
			continue;
		}

		if (k < (c[i] - last) * i) {
			mins = last + k / i;
			break;
		}

		k -= (c[i] - last) * i;
		last = c[i];
	}

	ll maxs = -1;

	reverse(c, c + n);
	k = lk;

	last = c[0];

	for (int i = 1; i < n; i++) {
		if (last == c[i]) {
			continue;
		}

		if (k < (last - c[i]) * i) {
			maxs = last - k / i;
			break;
		}

		k -= (last - c[i]) * i;
		last = c[i];
	}

	if (mins == -1 || maxs == -1) {
		throw 1;
	}

	//cout << mins << ' ' << maxs << endl;
	//cout << stup(n, lk) << endl;

	cout << maxs - mins << endl;

	return 0;
}