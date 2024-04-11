#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		if (n == 2 && s[0] >= s[1]) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			cout << 2 << '\n';
			cout << s[0] << ' ' << s.substr(1) << '\n';
		}
	}
}