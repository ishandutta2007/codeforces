#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = (int)s.length();
	bool was[26];
	for (int i = 0; i < 26; i++) {
		was[i] = false;
	}
	for (int i = 0; i < n; i++) {
		int k = (int)(s[i] - 'a');
		was[k] = true;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += was[i] == true;
	}
	if (ans % 2 == 0) {
		cout << "CHAT WITH HER!" << endl;
	} else {
		cout << "IGNORE HIM!" << endl;
	}
}