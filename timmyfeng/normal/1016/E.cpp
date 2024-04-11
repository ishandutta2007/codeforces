#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(15);

	int sy, a, b, n;
	cin >> sy >> a >> b >> n;
	vector<pair<double, int>> pt;
	vector<int> ps(1);
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		pt.emplace_back(l, 0);
		pt.emplace_back(r, 1);
		ps.emplace_back(ps.back() + r - l);
	}
	pt.emplace_back(2e9, 0);

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;

		double start_x = a - (double)(x - a) / (y - sy) * sy;
		double end_x = b - (double)(x - b) / (y - sy) * sy;
		auto start_it = lower_bound(pt.begin(), pt.end(), make_pair(start_x, 0));
		auto end_it = lower_bound(pt.begin(), pt.end(), make_pair(end_x, 0));
		double ans = 0;

		int start_ndx = 0;
		if (start_it->second) {
			ans += start_it->first - start_x;
			start_ndx = (start_it - pt.begin() + 1) / 2;
		} else {
			start_ndx = (start_it - pt.begin()) / 2;
		}

		int end_ndx = 0;
		if (end_it->second) {
			ans -= end_it->first - end_x;
			end_ndx = (end_it - pt.begin() + 1) / 2;
		} else {
			end_ndx = (end_it - pt.begin()) / 2;
		}

		ans += ps[end_ndx] - ps[start_ndx];
		cout << ans / (end_x - start_x) * (b - a) << '\n';
	}
}