#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int) s.length(); i++) {
		int indeks = (int) (s[i] - '0');
		ans += a[indeks - 1];
	}
	cout << ans;
	return 0;
}