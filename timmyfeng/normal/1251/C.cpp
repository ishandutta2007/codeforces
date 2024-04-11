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
		string even = "", odd = "";
		for (int i = (int)s.size() - 1; ~i; --i) {
			if (s[i] % 2) {
				odd += s[i];
			} else {
				even += s[i];
			}
		}
		
		for (int i = 0; i < (int)s.size(); ++i) {
			char e = (even.empty() ? 'a' : even.back());
			char o = (odd.empty() ? 'a' : odd.back());
			if (e < o) {
				even.pop_back();
				cout << e;
			} else {
				odd.pop_back();
				cout << o;
			}
		}	
		cout << '\n';
	}
}