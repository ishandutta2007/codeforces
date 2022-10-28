#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] + a[i - 1] == 5) {
			cout << "Infinite" << '\n';
			return 0;
		} else if (i > 1 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) {
			--ans;
		}
		ans += a[i] + a[i - 1];
	}
	cout << "Finite" << '\n';
	cout << ans << '\n';
}