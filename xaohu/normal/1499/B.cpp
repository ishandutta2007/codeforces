#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int T;
string s;

void solve() {
	cin >> s;
	bool x = 0;
	rep(i, 1, (int)s.size() - 1) 
		if (s[i] == s[i - 1]) {
			if (s[i] == '1') x = 1;
			else if (x == 1) 
				return cout << "NO\n", void(0);
		}
	cout << "YES\n";
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}