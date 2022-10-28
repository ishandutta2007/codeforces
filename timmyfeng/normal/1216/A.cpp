#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			++ans;
			s[i] = 'a' + 'b' - s[i];
		}
	}
	cout << ans << '\n';
	cout << s << '\n';
}