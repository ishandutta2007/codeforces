#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	
	int ans = n;
	for (int i = 1; i * 2 <= n; ++i) {
		if (s.substr(0, i) == s.substr(i, i)) {
			ans = n - i + 1;
		}
	}
	cout << ans << '\n';
}