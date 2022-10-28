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
		vector<int> a(s.size()), cnt(3);
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] <= '9') {
				a[i] = 0;
				++cnt[0];
			} else if (s[i] <= 'Z') {
				a[i] = 1;
				++cnt[1];
			} else {
				a[i] = 2;
				++cnt[2];
			}
		}
		if (cnt[0] && cnt[1] && cnt[2]) {
			;
		} else if (!!cnt[0] + !!cnt[1] + !!cnt[2] == 2) {
			int c = 0;
			while (cnt[c]) {
				++c;
			}
			if (cnt[a[0]] > 1) {
				s[0] = "0Aa"[c];
			} else {
				s[1] = "0Aa"[c];
			}
		} else {
			int i = 0;
			for (int j = 0; j < 3; ++j) {
				if (!cnt[j]) {
					s[i++] = "0Aa"[j];
				}
			}
		}
		cout << s << '\n';
	}
}