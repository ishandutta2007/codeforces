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
		vector<int> ans;
		vector<bool> vstd(n + 1);
		for (int i = 0; i < 2 * n; ++i) {
			int a;
			cin >> a;
			if (!vstd[a]) {
				ans.push_back(a);
				vstd[a] = true;
			}
		}
		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}