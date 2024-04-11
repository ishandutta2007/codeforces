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

	int mx = *max_element(a.begin(), a.end());
	int ans = 0;
	for (auto i : a) {
		ans = __gcd(ans, mx - i);
	}

	long long cnt = 0;
	for (auto i : a) {
		cnt += (mx - i) / ans;
	}
	cout << cnt << ' ' << ans << '\n';
}