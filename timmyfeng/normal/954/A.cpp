#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i, ++ans) {
		if (i + 1 < n && s[i] != s[i + 1]) {
			++i;
		}
	}
	cout << ans << '\n';
}