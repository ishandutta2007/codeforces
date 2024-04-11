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
		string ans;
		for (int i = 0; i < int(s.size()); i += 2) {
			ans += s[i];
		}
		ans += s.back();
		cout << ans << "\n";
	}
}