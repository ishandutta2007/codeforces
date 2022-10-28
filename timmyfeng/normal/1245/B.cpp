#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;
		string ans(s.size(), 0);
		int ct = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == 'R' && b) {
				--b;
				ans[i] = 'P';
			} else if (s[i] == 'P' && c) {
				--c;
				ans[i] = 'S';
			} else if (s[i] == 'S' && a) {
				--a;
				ans[i] = 'R';
			}
			ct += !!ans[i];
		}
		if (ct < (n + 1) / 2) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for (auto& i : ans) {
				if (!i) {
					if (a) {
						--a;
						i = 'R';
					} else if (b) {
						--b;
						i = 'P';
					} else {
						--c;
						i = 'S';
					}
				}
			}
			cout << ans << '\n';
		}
	}
}