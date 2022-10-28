#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	vector<int> ans;
	for (int i = 1; i <= 2000; ++i) {
		int cur = 0;
		bool ok = true;
		for (int j = 0; j < n && ok; ++j) {
			while (cur < n && a[cur] <= i + j) {
				++cur;	
			}
			ok &= cur - j > 0 && p != cur - j;
		}
		if (ok) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << "\n";
	for (auto& i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}