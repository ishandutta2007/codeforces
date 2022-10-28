#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, h;
	cin >> n >> h;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int ans = 0;
	for ( ; ans < n; ++ans) {
		sort(a.begin(), a.begin() + ans + 1, greater<int>());	
		long long res = 0;
		for (int i = 0; i <= ans; i += 2) {
			res += a[i];
		}
		if (res > h) {
			break;
		}
	}
	cout << ans << "\n";
}