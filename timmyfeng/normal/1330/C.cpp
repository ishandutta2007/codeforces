#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for (auto& i : l) {
		cin >> i;
	}

	vector<int> ans(m, 1);
	ans[m - 1] = 0;
	ll cur = n;
	for (int i = m - 1; ~i; --i) {
		cur -= ans[i];
		while (cur + l[i] - 1 > n) {
			--cur;
			++ans[i];
		}
	}
	ll sum = n - ans[m - 1];
	for (int i = m - 2; ~i && cur > 1; --i) {
		while (cur > 1 && sum - ans[i] + l[i] - 1 >= sum) {
			++ans[i];
			--cur;
		}
	}
	for (int i = m - 2; ~i; --i) {
		ans[i] += ans[i + 1];
	}
	if (cur != 1) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 0; i < m; ++i ){
		cout << n - ans[i] << ' ' ;
	}
	cout << '\n';
}