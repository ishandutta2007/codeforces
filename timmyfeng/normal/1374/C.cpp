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
		int bal = 0;
		int mn = 0;
		for (auto c : s){
			if (c == '(') {
				++bal;
			} else {
				--bal;
			}
			mn = min(mn, bal);
		}
		cout << -mn << "\n";
	}
}