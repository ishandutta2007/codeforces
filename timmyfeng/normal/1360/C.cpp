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
		int odd = 0, even = 0;
		for (auto& i : a) {
			cin >> i;
			++(i % 2 ? odd : even);
		}
		sort(a.begin(), a.end());

		bool ok = false;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i + 1] - a[i] == 1) {
				ok = true;
			}
		}
		
		cout << (odd % 2 == 0 || ok ? "YES" : "NO") << '\n';
	}
}