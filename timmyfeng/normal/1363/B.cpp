#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		
		vector<int> suf(n + 1), pre(n + 1);
		for (int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + (s[i] == '1');
			suf[n - i - 1] = suf[n - i] + (s[n - i - 1] == '1');
		}

		int ans = 1e9;
		for (int i = 0; i <= n; ++i) {
			ans = min({ans, i - pre[i] + suf[i], pre[i] + n - i - suf[i]});
		}

		cout << ans << '\n';
	}
}