#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
	int n = s.size();
	vector<int> pi(n);
	int link = 0;
	for (int i = 1; i < n; ++i) {
		while (link && s[i] != s[link]) {
			link = pi[link - 1];
		}
		if (s[i] == s[link]) {
			++link;
		}
		pi[i] = link;
	}
	return pi;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int n = t.size();

	int overlap = prefix_function(t)[n - 1];

	int one = 0;
	int zero = 0;
	for (auto i : s) {
		if (i == '0') {
			++zero;
		} else {
			++one;
		}
	}

	string ans = "";
	int period_one = 0;
	int period_zero = 0;
	for (int i = 0; i < n; ++i) {
		if (i < overlap) {
			if (t[i] == '0') {
				--zero;
			} else {
				--one;
			}
		} else {
			if (t[i] == '0') {
				++period_zero;
			} else {
				++period_one;
			}
		}
	}

	if (zero < 0 || one < 0) {
		cout << s << "\n";
		exit(0);
	}

	ans += t.substr(0, overlap);

	while (zero >= period_zero && one >= period_one) {
		zero -= period_zero;
		one -= period_one;
		ans += t.substr(overlap);
	}

	ans += string(zero, '0') + string(one, '1');
	cout << ans << "\n";
}