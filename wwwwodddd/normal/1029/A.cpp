#include <bits/stdc++.h>
using namespace std;
int n, k, t;
string s;
int main() {
	cin >> n >> k;
	cin >> s;
	for (t = 1;; t++) {
		if (s.substr(t, n - t) == s.substr(0, n - t)) {
			break;
		}
	}
	cout << s;
	for (int i = 1; i < k; i++) {
		cout << s.substr(n - t, t);
	}
	cout << endl;
	return 0;
}