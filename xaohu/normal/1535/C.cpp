#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

int t, n;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> s;
		n = sz(s);
		ll res = 0, cnt = 0, val = 0;
		int last[2][2];
		memset(last, -1, sizeof last);
		rep(i, 0, n - 1) {
			if (s[i] == '?') {
				cnt++;
				res += cnt + val;
			}
			else {
				int x = s[i] - '0', y = (i & 1);
				val = (i - max(last[x][!y], last[!x][y]));
				res += val;
				last[x][y] = i;
				cnt = 0;
			}
		}
		cout << res << "\n";		
	}
		
	return 0;
}