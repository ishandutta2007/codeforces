#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		map<int, int> p, q;

		for(int cur = 1; cur <= n; ++cur) {
			int a[m]; for(int &i : a) cin >> i;

			for(int i = 1; i < m; ++i) a[i] += a[i-1];

			int sum {};
			for(int i = 0; i < m; ++i) sum += a[i];

			++p[sum];
			q[sum] = cur;
		}

		vector<int> oh;
		for(auto [i, j] : p)
			oh.push_back(i);

		cout << q[oh[0]] << ' ' << oh[1] - oh[0] << '\n';
	}
}