#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, l;
	cin >> n >> k >> l;
	int m = n * k;
	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	int cnt = 0;
	int cap = a[0] + l;
	for (int i = m - 1; i >= 0; --i) {
		if (a[i] <= cap && (cnt + 1) * k <= m - i) {
			ans += a[i];
			++cnt;
		}
	}
	cout << (cnt == n ? ans : 0) << '\n';
}