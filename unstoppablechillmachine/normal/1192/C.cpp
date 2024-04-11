#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int MOD = 998244353;
const ll MOD2 = MOD * 1ll * MOD;
void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void add2(ll &a, ll b) {
	a += b;
	if (a >= MOD2) {
		a -= MOD2;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

const int MX = 62;
int dp[11][MX][MX][MX];
int cnt[11][MX][MX];

int get(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	if (c >= 'A' && c <= 'Z') {
		return 26 + (c - 'A');
	}
	return 52 + (c - '0');
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	set<string> mp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (mp.find(s) == mp.end()) {
			cnt[SZ(s)][get(s[0])][get(s.back())]++;
			mp.insert(s);	
		}
		reverse(all(s));
		if (mp.find(s) == mp.end()) {
			cnt[SZ(s)][get(s[0])][get(s.back())]++;
			mp.insert(s);	
		}
	}
	int ans = 0;
	for (int len = 3; len <= 10; len++) {
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				for (int k = 0; k < MX; k++) {
					ll res = 0;
					for (int letter = 0; letter < MX; letter++) {
						res += cnt[len][i][letter] * 1ll * cnt[len][j][letter] * cnt[len][k][letter];
					}
					dp[len][i][j][k] = res % MOD;
				}
			}
		}

		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				for (int k = 0; k < MX; k++) {
					if (!dp[len][i][j][k]) {
						continue;
					}
					ll sum = 0;
					for (int p = 0; p < MX; p++) {
						add2(sum, mult(dp[len][i][k][p], dp[len][i][j][p]) * 1ll * dp[len][j][k][p]);
					}
					sum %= MOD;
					add(ans, mult(dp[len][i][j][k], sum));
				}
			}
		}
	}
	cout << ans << '\n';
}