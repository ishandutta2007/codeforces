#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<tuple<int, int, int>>& pairs) {
	sort(pairs.begin(), pairs.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<1>(a) > get<1>(b);
	});

	vector<int> res;
	for (auto i : pairs) {
		res.push_back(get<2>(i));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, int, int>> pairs1, pairs2;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			pairs1.emplace_back(a, b, i);
		} else {
			pairs2.emplace_back(-a, -b, i);
		}
	}

	vector<int> ans1 = solve(pairs1);
	vector<int> ans2 = solve(pairs2);

	if (ans1.size() < ans2.size()) {
		swap(ans1, ans2);
	}

	cout << ans1.size() << "\n";
	for (auto i : ans1) {
		cout << i << " ";
	}
	cout << "\n";
}