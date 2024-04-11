#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	int m;
	cin >> n >> m >> k;

	vector<long long> p(m);
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
		--p[i];
	}

	int cur = 0;
	int ans = 0;
	while (cur < m) {
		int offset = cur;
		long long start = (p[cur] - offset) - (p[cur] - offset) % k;
		while (cur < m && p[cur] - offset < start + k) {
			++cur;
		}
		++ans;
	}
	cout << ans << "\n";
}