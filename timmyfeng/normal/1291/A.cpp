#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		string sol = "";
		for (char c : s) {
			if (c % 2) {
				sol += c;
			}
		}
		if (sol.size() >= 2) {
			cout << sol.substr(0, 2) << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}