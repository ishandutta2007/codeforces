#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

vector<pair<int, int>> stk;
map<int, int> cnt;
int ans[MX];

pair<int, int> query(int l, int r) {
	cout << "? " << l << " " << r << endl;
	pair<int, int> res;
	cin >> res.first >> res.second;
	return res;
}

void solve(int l, int r) {
	if (l > r)
		return;

	auto [x, f] = query(l, r);
	if (cnt.count(x)) {
		for (int i = r - f + 1; i <= r - f + cnt[x]; ++i) {
			ans[i] = x;
		}
		cnt.erase(x);
		solve(l, r - f);
	} else {
		cnt[x] = f;
		while (cnt.count(x)) {
			solve(l, l + f - 1);
			l += f;
		}
		while (ans[l]) {
			++l;
		}
		solve(l, r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	solve(1, n);

	cout << "!";
	for (int i = 1; i <= n; ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
}