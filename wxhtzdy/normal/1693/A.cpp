#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		if (sum != 0) {
			cout << "No\n";
			continue;
		}
		while (!a.empty() && a.back() == 0) a.pop_back();
		if (a.empty()) {
			cout << "Yes\n";
			continue;
		}
		n = (int) a.size();
		vector<long long> suf(1, 0);
		for (int i = n - 1; i >= 0; i--) {
			suf.push_back(suf.back() + a[i]);
		}
		bool ok = true;
		for (int i = 1; i < (int) suf.size() - 1; i++) {
			if (suf[i] >= 0) ok = false;
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
}