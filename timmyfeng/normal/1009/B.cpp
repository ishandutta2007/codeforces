#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();
	string ans = "";
	int one = count(s.begin(), s.end(), '1');
	int i = 0;
	while (i < n && s[i] != '2') {
		if (s[i] == '0') {
			ans += '0';
		}
		++i;
	}
	ans += string(one, '1');
	for ( ; i < n; ++i) {
		if (s[i] != '1') {
			ans += s[i];
		}
	}
	cout << ans << '\n';
}