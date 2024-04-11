#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	ll pos = 0, neg = 0, ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			swap(pos, neg);
			++neg;
		} else {
			++pos;
		}
		ans2 += pos;
		ans1 += neg;
	}
	cout << ans1 << ' ' << ans2 << '\n';
}