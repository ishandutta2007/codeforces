#include <bits/stdc++.h>

using namespace std;

int T, n;
string s;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> s;
		string a(n, 'a'), b(n, 'a');
		int cnt0 = count(s.begin(), s.end(), '0');
		int cnt1 = count(s.begin(), s.end(), '1');
		if (s[0] == '1' && s[n - 1] == '1' && cnt0 % 2 == 0) {
			int c = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') 
					a[i] = b[i] = c++ < cnt1 / 2 ? '(' : ')';
				else {
					a[i] = cnt0 % 2 ? '(' : ')';
					b[i] = cnt0++ % 2 ? ')' : '(';
				}
			}
			cout << "YES\n" << a << "\n" << b << "\n";
		}
		else 
			cout << "NO\n";
	}
	return 0;
}