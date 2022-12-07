#include <bits/stdc++.h>

using namespace std;

int t, a, b;
string s;

void solve() {
	cin >> a >> b >> s;
	int cnt[2] {};
	vector<int> p;
	for (int i = 0; i <= a + b - i - 1; i++) {
		if (i == a + b - i - 1) {
			if (s[i] != '?') {
				cnt[s[i] - '0']++;
			}
			else if (a % 2 != cnt[0] % 2) {
				cnt[0]++, s[i] = '0';
			}
			else {
				cnt[1]++, s[i] = '1';
			}
			break;
		}
		if (s[i] == '?')
			swap(s[i], s[a + b - i - 1]);
		if (s[i] == '?') 
			p.push_back(i);
		else {
			if (s[a + b - i - 1] != '?' && s[a + b - i - 1] != s[i]) {
				cout << "-1\n";
				return;
			}
			cnt[s[i] - '0'] += 2;
			s[a + b - i - 1] = s[i];
		}	
	}
	if (cnt[0] % 2 != a % 2 || cnt[1] % 2 != b % 2 || cnt[0] > a || cnt[1] > b) {
		cout << "-1\n";
		return;
	}
	while (!p.empty()) {
		int x = p.back();
		p.pop_back();
		int what = (cnt[0] < a ? 0 : 1);
		cnt[what] += 2;
		s[x] = s[a + b - 1 - x] = (char) ('0' + what);
	}
	cout << s << "\n";
}

int main() {
	cin >> t;
	while (t--)
		solve();
	return 0;
}