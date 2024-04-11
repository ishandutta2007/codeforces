#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a(3);
	for (auto& i : a) {
		string s;
		cin >> s;
		i = (s[0] - '0') + (s[1] - 'm') * 5;
	}
	sort(a.begin(), a.end());

	int ans = 2;
	for (int i = 0; i < 2; ++i) {
		if (a[i] + 2 >= a[i + 1]) {
			ans = 1;
		}
	}
	if (a[0] == a[2] || (a[0] + 1 == a[1] && a[1] + 1 == a[2])) {
		ans = 0;
	}
	cout << ans << "\n";
}