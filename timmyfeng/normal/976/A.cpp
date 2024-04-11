#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	if (s[0] == '0') {
		cout << '0' << '\n';
	} else {
		int cnt = count(s.begin(), s.end(), '0');
		cout << 1 << string(cnt, '0') << '\n';
	}
}