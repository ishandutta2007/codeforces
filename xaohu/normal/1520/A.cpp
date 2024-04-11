#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		bool ok = 1;
		rep(i, 0, n - 1)
			rep(j, i + 1, n - 1)
				rep(k, j + 1, n - 1)
					if (s[i] == s[k] && s[i] != s[j])
						ok = 0;
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}