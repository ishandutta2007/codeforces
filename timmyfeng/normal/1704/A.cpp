#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;
		cout << (a.substr(n - m + 1) == b.substr(1) && count(a.begin(), a.end() - m + 1, b[0]) ? "YES" : "NO") << "\n";
	}
}