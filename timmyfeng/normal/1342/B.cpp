#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (!count(s.begin(), s.end(), '1') || !count(s.begin(), s.end(), '0')) {
			cout << s << '\n';
		} else {
			for (int i = 0; i < (int)s.size(); ++i) {
				cout << "01";
			}
			cout << '\n';
		}
	}
}