#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;

		bool ok = false;
		for (char i = 'a'; i <= 'z'; ++i) {
			ok |= (count(s.begin(), s.end(), i) && count(t.begin(), t.end(), i));
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}