#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int diff = 0, ct = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			ct += (i < n / 2 ? -1 : 1);
		} else {
			diff += (i < n / 2 ? -(s[i] - '0') : s[i] - '0');
		}
	}
	cout << (ct / 2 * 9 == -diff ? "Bicarp" : "Monocarp") << '\n';
}