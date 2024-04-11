#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <set>
#include <cassert>
#include <map>
#include <math.h>
#include <unordered_map>
#include <queue>
#define ll long long
#define ld long double 

using namespace std;

const int maxn = (int)1e5 + 10;

pair <double, double> v[maxn];

multiset <double> s;

ll getr(double x, double y) {
	double d = abs(x - y);

	if ((ll)(d + 0.9) == 0) {
		return 1;
	}

	return (ll)(d + 0.9);
}

ll go(int k) {
	vector <double> a;

	int cnt = 0;

	for (auto it = s.begin(); it != s.end(); it++) {
		if (cnt > k) {
			break;
		}

		a.push_back(*it);
		cnt++;
	}

	cnt = 0;
	vector <double> b;

	for (auto it = s.rbegin(); it != s.rend(); it++) {
		if (cnt > k) {
			break;
		}

		b.push_back(*it);
		cnt++;
	}

	reverse(b.begin(), b.end());

	ll ans = (ll)1e18;

	for (int i = 0; i <= k; i++) {
		ans = min(ans, getr(a[i], b[i]));
	}

	return ans;
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		v[i] = make_pair((x1 + x2) * 1.0 / 2, (y1 + y2) * 1.0 / 2);
	}

	sort(v, v + n);

	long long ans = (ll)2e18;

	for (int i = 0; i <= k; i++) {
		s.clear();
		for (int j = i; j < n; j++) {
			s.insert(v[j].second);
		}

		for (int t = 0; t <= k - i; t++) {
			ans = min(ans, getr(v[i].first, v[n - t - 1].first) * go(k - i - t));

			s.erase(s.find(v[n - t - 1].second));
		}
	}

	cout << ans << endl;

	return 0;
}