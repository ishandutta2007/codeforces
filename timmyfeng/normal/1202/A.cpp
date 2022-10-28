#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		int k = 1;
		for ( ; t[t.size() - k] == '0'; ++k);
		int ans = 0;
		for ( ; s[s.size() - k - ans] == '0'; ++ans);
		cout << ans << '\n';
	}
}