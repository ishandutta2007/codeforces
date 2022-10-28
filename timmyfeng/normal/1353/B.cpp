#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		for (auto& i : a) {
			cin >> i;
		}
		for (auto& i : b) {
			cin >> i;
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < k; ++i) {
			a.push_back(b.back());
			b.pop_back();
		}
		sort(a.begin(), a.end(), greater<int>());
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
		}
		cout << sum << '\n';
	}
}