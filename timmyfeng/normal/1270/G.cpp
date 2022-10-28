#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] = i - a[i];
		}

		int tort = a[1];
		int hare = a[a[1]];
		while (tort != hare) {
			tort = a[tort];
			hare = a[a[hare]];
		}

		vector<int> ans = {tort};
		hare = a[tort];
		while (tort != hare) {
			ans.push_back(hare);
			hare = a[hare];
		}

		cout << ans.size() << "\n";
		for (auto i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}