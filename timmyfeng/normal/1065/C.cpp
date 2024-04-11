#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> freq(2e5 + 1);
	int cnt = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mx = max(mx, a);
		if (!freq[a]) {
			++cnt;
		}
		++freq[a];
	}

	int ans = 0;
	while (cnt > 1) {
		int cur = 0;
		while (cnt > 1 && freq[mx] + cur <= k) {
			if (!freq[mx - 1]) {
				++cnt;
			}
			freq[mx - 1] += freq[mx];
			cur += freq[mx];
			freq[mx] = 0;
			--cnt;
			--mx;
		}
		++ans;
	}
	cout << ans << '\n';
}