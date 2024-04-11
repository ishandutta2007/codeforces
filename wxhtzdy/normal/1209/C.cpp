#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int l = 0;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			l = max(l, (int) (s[i] - '0'));
			m[(int) (s[i] - '0')]++;
		}
		vector<bool> was(n, false);
		for (int i = n - 1; i >= 0; i--) {
			int digit = (int) (s[i] - '0');
			if (digit == l) {
				was[i] = true;
				m[l]--;
			}
			while (m[l] == 0 && l >= 0) {
				l--;
			}
			if (l < 0) {
				break;
			}
		}
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < n; i++) {
			int digit = (int) (s[i] - '0');
			if (was[i] == true) {
				a.push_back(digit);
			} else {
				b.push_back(digit);
			}
		}
		bool ok = true;
		for (int i = 1; i < (int) a.size(); i++) {
			if (a[i] < a[i - 1]) {
				ok = false;
			}
		}
		for (int i = 1; i < (int) b.size(); i++) {
			if (b[i] < b[i - 1]) {
				ok = false;
			}
		}
		if (ok == false) {
			cout << '-' << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << (was[i] == false ? 1 : 2);
			}
			cout << endl;
		}
	}
	return 0;
}