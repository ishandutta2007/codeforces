#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

int a[MX + 1], pos[MX + 1], ub[MX + 1], lb[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	vector<int> stk;
	for (int i = 1; i <= n; ++i) {
		while (!stk.empty() && a[i] > a[stk.back()]) {
			stk.pop_back();
		}
		lb[i] = stk.empty() ? 0 : stk.back();
		stk.push_back(i);
	}
	stk.clear();
	for (int i = n; i; --i) {
		while (!stk.empty() && a[i] > a[stk.back()]) {
			stk.pop_back();
		}
		ub[i] = stk.empty() ? n + 1 : stk.back();
		stk.push_back(i);
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i - lb[i] < ub[i] - i) {
			for (int j = lb[i] + 1; j < i; ++j) {
				int tgt = a[i] - a[j];
				ans += (tgt >= 1 && tgt <= n && pos[tgt] > i && pos[tgt] < ub[i]);
			}
		} else {
			for (int j = i + 1; j < ub[i]; ++j) {
				int tgt = a[i] - a[j];
				ans += (tgt >= 1 && tgt <= n && pos[tgt] > lb[i] && pos[tgt] < i);
			}
		}
	}
	cout << ans << '\n';
}