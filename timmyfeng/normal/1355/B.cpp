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
		sort(a.begin(), a.end());

		int ans = 0, first = 0, last = -1;
		for (int i = 0; i < n; ++i) {
			if (last - first + 1 < a[i]) {
				last = first + a[i] - 1;
			}
			if (last == i) {
				++ans;
				first = last + 1;
				last = -1;
			}
		}
		cout << ans << '\n';
	}
}