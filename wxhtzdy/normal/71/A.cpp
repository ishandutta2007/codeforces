#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = (int)s.length();
		if (n <= 10) {
			cout << s << endl;
		} else {
			cout << s[0] << n - 2 << s[n - 1] << endl;
		}
	}
}