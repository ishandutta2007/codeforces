#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t, s;
	cin >> n >> t >> s;
	vector<int> dt(n + 1), ds(n + 1), ans(n + 1);
	int ext;
	for (int i = n - 1; i; --i) {
		if (i == 2) {
			cout << "+ " << 1 << endl;
			int nt, ns;
			cin >> nt >> ns;
			ext = ns - s;
			t = nt;
			s = ns;
		}
		cout << "+ " << i << endl;
		int nt, ns;
		cin >> nt >> ns;
		dt[i] = nt - t;
		ds[i] = ns - s;
		t = nt;
		s = ns;
	}
	
	for (int i = 0; i + ans[1] < dt[1]; i += ans[1], ++ans[1]);
	ans[3] = ds[1] - ext - 1;
	ans[2] = ext / (ans[3] + 1);
	ans[4] = (ds[2] - (ans[1] + 1) * (ans[3] + 1)) / (ans[3] + 1) - 1;

	for (int i = 5; i <= n; ++i) {
		ans[i] = (ds[i - 2] - ans[i - 4] * ans[i - 3] - ans[i - 3] * (ans[i - 1] + 1)) / (ans[i - 1] + 1) - 1;
	}

	cout << "! ";
	++ans[n];
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}