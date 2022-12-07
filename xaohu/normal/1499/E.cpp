#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int P = 998244353;

int n, m, dp[1010][1010][26];
string s, t;
ll res;
 
int main() {
	cin >> s >> t;
	n = s.size();
	m = t.size();
	per(i, 0, n)
		per(j, 0, m) {
			rep(c, 0, 25) {
				dp[i][j][c] = 1;
				if (i < n && s[i] - 'a' != c)
					dp[i][j][c] = (dp[i][j][c] + dp[i + 1][j][s[i] - 'a']) % P;
				if (j < m && t[j] - 'a' != c)
					dp[i][j][c] = (dp[i][j][c] + dp[i][j + 1][t[j] - 'a']) % P;
			}
			if (i < n && j < m)
				res = (res + dp[i + 1][j][s[i] - 'a'] + dp[i][j + 1][t[j] - 'a']) % P;
		}
	rep(r, 0, 1) {
		ll len = 0, lst = -1;
		rep(i, 0, n - 1) {
			if (s[i] - 'a' != lst) len++;
			else len = 1;
			lst = s[i] - 'a';
			res = (res - len * m % P + P) % P;
		}
		swap(n, m);
		swap(s, t);
	}
	cout << res << endl;
	return 0;
}