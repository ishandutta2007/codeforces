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
		
		int ans = 0;
		for ( ; ans < n; ++ans) {
			if (s[ans] == '>' || s[n - 1 - ans] == '<')
				break;
		}
		cout << ans << '\n';
	}
}