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

		int cnt = count(s.begin(), s.end(), '1');
		int num = min(int(s.size()) - cnt, cnt);

		cout << (num % 2 ? "DA" : "NET") << "\n";
	}
}