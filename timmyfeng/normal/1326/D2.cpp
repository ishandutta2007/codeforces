#include <bits/stdc++.h>
using namespace std;

int pi[2000001];

string preF(string s) {
	int n = (int)s.size(), j = 0;
	for (int i = 1; i < n; ++i) {
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
	}
	return s.substr(0, j);
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int j = n - 1, i = 0;
		while (i < j && s[i] == s[j]) {
			++i;
			--j;
		}
		string mid = s.substr(i, j - i + 1);
		string rev = mid;
		reverse(rev.begin(), rev.end());
		string ans1 = preF(mid + '#' + rev);
		string ans2 = preF(rev + '#' + mid);
		cout << s.substr(0, i) << (ans1.size() > ans2.size() ? ans1 : ans2) << s.substr(j + 1) << '\n';
	}
}