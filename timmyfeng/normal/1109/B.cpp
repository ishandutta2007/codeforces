#include <bits/stdc++.h>
using namespace std;

bool palindrome(string& t) {
	bool ok = true;
	int n = t.size();
	for (int i = 0; i < n; ++i) {
		ok &= (t[i] == t[n - 1 - i]);
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	for (int i = 1; i < n - 1; ++i) {
		string t = s.substr(i) + s.substr(0, i);
		if (t != s && palindrome(t)) {
			cout << 1 << "\n";
			exit(0);
		}
	}

	for (int i = 1; i <= n / 2; ++i) {
		string t = s.substr(n - i) + s.substr(i, n - 2 * i) + s.substr(0, i);
		if (t != s && palindrome(t)) {
			cout << 2 << "\n";
			exit(0);
		}
	}

	cout << "Impossible\n";
}