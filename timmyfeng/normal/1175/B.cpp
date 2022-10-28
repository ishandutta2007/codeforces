#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> stk = {1};
	vector<ll> cnt = {0};
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		if (t[0] == 'f') {
			int m;
			cin >> m;
			stk.push_back(m);
			cnt.push_back(0);
		} else if (t[0] == 'a') {
			++cnt.back();
			if (cnt.back() >= (1LL << 32)) {
				cout << "OVERFLOW!!!" << '\n';
				return 0;
			}
		} else {
			ll tmp = cnt.back() * stk.back();
			cnt.pop_back();
			stk.pop_back();
			cnt.back() += tmp;
			if (cnt.back() >= (1LL << 32)) {
				cout << "OVERFLOW!!!" << '\n';
				return 0;
			}
		}
	}
	cout << cnt[0] << '\n';
}