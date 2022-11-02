#include <bits/stdc++.h>
using namespace std;
#define int long long
using ii = array<int, 2>;

const int VAL = 1e9;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, v;
	cin >> n >> v;

	int t[n], a[n];
	for(int &i : t) cin >> i, i *= v;
	for(int &i : a) cin >> i;

	ii b[n];
	for(int i = 0; i < n; ++i)
		b[i] = {a[i] + t[i], a[i] - t[i]};

	sort(b, b + n, [](const ii &x, const ii &y) {
		if(x[0] == y[0]) return x[1] > y[1];
		return x[0] < y[0];
	});

	reverse(b, b + n);
	vector<int> c;

	for(auto [_, i] : b) if(_ >= 0) {
		if(empty(c) || i >= c.back()) c.push_back(i);
		else *upper_bound(begin(c), end(c), i) = i;
	}

	cout << upper_bound(begin(c), end(c), 0) - begin(c);
}