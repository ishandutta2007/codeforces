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
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		vector<int> ans;
		for (auto i : a) {
			if (ans.size() >= 2u && (i > ans.back()) == (ans.back() > ans[ans.size() - 2u])) {
				ans.pop_back();
			}
			ans.push_back(i);
		}

		cout << ans.size() << '\n';
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}