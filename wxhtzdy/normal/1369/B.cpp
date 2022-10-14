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
		string left = "", right = "";
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				break;
			}
			left += s[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0') {
				right += s[i];
				break;
			}
			right += s[i];
		}
		reverse(right.begin(), right.end());
		if (n <= (int)left.length() + (int)right.length()) {
			cout << s << endl;
		} else {
			cout << left + right << endl;
		}
	}
	return 0;
}