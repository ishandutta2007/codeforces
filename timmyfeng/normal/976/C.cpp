#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, int, int>> seg;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		seg.emplace_back(l, r, i);
	}
	sort(seg.begin(), seg.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<0>(a) == get<0>(b) ? get<1>(a) > get<1>(b) : get<0>(a) < get<0>(b);
	});

	int mx_r = 0, j = 0;
	for (auto [l, r, i] : seg) {
		if (r <= mx_r) {
			cout << i << ' ' << j << '\n';
			return 0;
		}
		if (r > mx_r) {
			mx_r = r;
			j = i;
		}
	}
	cout << -1 << ' ' << -1 << '\n';
}