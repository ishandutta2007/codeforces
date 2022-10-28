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

	int mn = *min_element(a.begin(), a.end());
	int pre = -1e9;
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mn) {
			ans = min(ans, i - pre);
			pre = i;
		}
	}
	cout << ans << '\n';
}