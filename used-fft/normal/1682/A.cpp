#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 1;
		for(int i = n/2; i++; ) {
			if(i == n || s[i] != s[n/2]) break;
			++ans;
		}
		cout << (2*ans - (n & 1)) << '\n';
	}
}