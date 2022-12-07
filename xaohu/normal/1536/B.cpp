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
string s, x;
map<string, int> m;

bool solve(int len, int p = 0) {
	if (p == len) {
		if (m[x] == 0) {
			cout << x << "\n";
			return 1;
		}
		return 0;
	}
	rep(c, 0, 25) {
		x += (char)('a' + c);
		int g = solve(len, p + 1);
		x.pop_back();
		if (g) return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> s;
		m.clear();
		rep(i, 0, n - 1) {
			string t;
			rep(j, i, n - 1) {
				t += s[j];
				m[t] = 1;
			}
		}
		rep(len, 1, n) 
			if (solve(len))
				break;
	}
	return 0;
}