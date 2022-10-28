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
		bool ok = true;
		for (int i = 0; i < n/ 2; ++i) {
			int dif = abs(s[n - 1 - i] - s[i]);
			if (dif && dif != 2) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}