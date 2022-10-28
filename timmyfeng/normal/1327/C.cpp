#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	string ans = "";
	ans += string(n - 1, 'U');
	ans += string(m - 1, 'L');
	for (int i = 0; i < n; ++i) {
		ans += string(m - 1, (i % 2 ? 'L' : 'R'));
		ans += 'D';
	}
	cout << ans.size() << '\n';
	cout << ans << '\n';
}