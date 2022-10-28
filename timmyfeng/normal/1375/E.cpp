#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> pos(n);
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&a](int i, int j) {
		return a[i] < a[j];
	});

	vector<pair<int, int>> ans;
	for (int i = n; i; --i) {
		for (int j = 1; j < i; ++j) {
			if (pos[j] < pos[j - 1]) {
				ans.emplace_back(pos[j], pos[j - 1]);
				swap(pos[j], pos[j - 1]);
			}
		}
	}

	cout << ans.size() << "\n";
	for (auto& i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << "\n";
	}
}