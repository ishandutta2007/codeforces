#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 5010;
int dp[N][N], mn1[N], mn2[N];

signed main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = SZ(s1), m = SZ(s2);
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i + 1][j + 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}	

	for (int L = 0; L < n; L++) {
		string s;
		for (int i = L; i < n; i++) {
			s.pb(s1[i]);
		}
		int l = 0, r = 1, sz = SZ(s);
		vector<int> z(sz);
		for (int i = 1; i < sz; i++) {
			z[i] = min(z[i - l], max(r - i, 0));
			while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) {
				z[i]++;
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
			mn1[L + 1] = max(mn1[L + 1], z[i]);
			mn1[L + i + 1] = max(mn1[L + i + 1], z[i]);
		}
	}

	for (int L = 0; L < m; L++) {
		string s;
		for (int i = L; i < m; i++) {
			s.pb(s2[i]);
		}
		int l = 0, r = 1, sz = SZ(s);
		vector<int> z(sz);
		for (int i = 1; i < sz; i++) {
			z[i] = min(z[i - l], max(r - i, 0));
			while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) {
				z[i]++;
			}
			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
			mn2[L + 1] = max(mn2[L + 1], z[i]);
			mn2[L + i + 1] = max(mn2[L + i + 1], z[i]);
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << mn1[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		cout << mn2[i] << ' ';
	}
	cout << '\n';*/
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] > max(mn1[i], mn2[j])) {
				ans = min(ans, max(mn1[i], mn2[j]) + 1);
			}
		}
	}
	cout << (ans == 1e9 ? -1 : ans) << '\n';	
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}