#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<long long, int> mp;
	long long sum = 0;
	vector<long long> pref(n);
	for (int i = n - 1; i >= 0; i--) {
		sum += a[i];
		mp[sum]++;
		pref[i] = sum;
	}
	long long ans = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		mp[pref[i]]--;
		if (mp[sum] > 0) {
			ans = max(ans, sum);
		}
	}
	cout << ans << '\n';
	return 0;
}