#include <bits/stdc++.h>
using namespace std;

const int MX = 20;

int a[1 << (MX + 1)];
bool ok[1 << (MX + 1)];
int g, h, n;
long long sum;

void f(int i) {
	int l = 2 * i;
	int r = 2 * i + 1;
	if (!a[l] && !a[r]) {
		a[i] = 0;
	} else {
		if (a[l] > a[r]) {
			a[i] = a[l];
			f(l);
		} else {
			a[i] = a[r];
			f(r);
		}
		if (!ok[r] && !ok[l] || !ok[r] && a[r] > a[l] || !ok[l] && a[l] > a[r]) {
			ok[i] = false;
			sum += a[i];
		}
		if (!a[l] && !a[r] && 32 - __builtin_clz(i) <= g) {
			ok[i] = false;
			sum += a[i];
		}
	}
}

void solve() {
	cin >> h >> g;
	n = 1 << h;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		ok[i] = true;
	}
	for (int i = n; i < 2 * n; ++i) {
		a[i] = 0;
	}
	
	sum = 0;
	vector<int> ans;
	for (int i = 1; i < (1 << g); ++i) {
		while (ok[i]) {
			f(i);
			ans.push_back(i);
		}
	}
	cout << sum << '\n';
	for (auto& i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}