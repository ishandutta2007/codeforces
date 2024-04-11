#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n;
string s[3];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s[0] >> s[1] >> s[2];
		string ans(3 * n, '0');
		n = 2 * n;
		int a[3]{}, p = 0;
		while (max({a[0], a[1], a[2]}) < n) {
			int cnt[2]{};
			FOR(i, 3)
				cnt[s[i][a[i]] - '0']++;
			ans[p] = '0' + (cnt[0] < cnt[1]);
			FOR(i, 3)
				if (s[i][a[i]] == ans[p])
					a[i]++;
			p++;
		}	
		if (count(a, a + 3, n) == 1) {
			int sec = -1;
			FOR(i, 3)
				if (a[i] < n && (sec == -1 || a[i] > a[sec]))
					sec = i;
			rep(i, a[sec], n - 1)
				ans[p++] = s[sec][i];
		}
		cout << ans << "\n";
	}
	return 0;
}