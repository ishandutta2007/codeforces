#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		int sum = 0;
		for(char c : s) sum += c - 'a' + 1;
		if(size(s) & 1) {
			sum -= min(s[0] - 'a' + 1, s.back() - 'a' + 1) * 2;
		}
		cout << (sum > 0 ? "Alice" : "Bob") << ' ' << abs(sum) << '\n';
	}
}