#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		if (s[0] == s.back()) {
			cout << -1 << '\n';
		} else {
			cout << s << '\n';
		}
	}
}