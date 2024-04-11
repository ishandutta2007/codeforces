#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p, k;
	cin >> n >> p >> k;

	vector<long long> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	long long ans = 0;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int res = (a[i] * k % p - a[i] * a[i] % p * a[i] % p * a[i] % p + p) % p;
		ans += mp[res]++;
	}
	cout << ans << "\n";
}