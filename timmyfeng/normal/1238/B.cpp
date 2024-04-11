#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());

		int push = 0, ans = 0;
		while (!a.empty() && a.back() > push) {
			int cur = a.back();
			while (a.back() == cur) {
				a.pop_back();
			}
			++ans;
			push += r;
		}
		cout << ans << '\n';
	}
}