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
			--i;
		}
		vector<bool> vstd(n);
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			if (!vstd[i]) {
				int cur = i, len = 0;
				do {
					++len;
					vstd[cur] = true;
					cur = a[cur];
				} while (!vstd[cur]);
				do {
					ans[cur] = len;
					cur = a[cur];
				} while (cur != i);
			}
		}
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}