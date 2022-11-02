#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		
		if(size(s) > 3) {
			int i = 10;
			for(char c : s) i = min(i, c - '0');
			cout << i << '\n';
		}
		else if(size(s) == 2) {
			cout << s[1] << '\n';
		} else {
			cout << min(s[0], min(s[1], s[2])) << '\n';
		}
	}
}