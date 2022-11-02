#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		int n = size(s);

		int sum {};
		bool ok = s[n-1] == 'B';
		for(const char &c : s) {
			if(c == 'A') ++sum;
			else --sum;
			ok = ok && sum >= 0;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}