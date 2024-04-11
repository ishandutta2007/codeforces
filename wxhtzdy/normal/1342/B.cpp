#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = (int)s.length();
		vector<int> v;
		bool ok = true;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				ok = false;
				break;
			}
		}
		if (ok == true) {
			cout << s << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			v.push_back(0);
			v.push_back(1);
		}
		for (int i = 0; i < (int)v.size(); i++) {
			cout << v[i];
		}
		cout << endl;
	}
}