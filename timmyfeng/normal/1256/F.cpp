#include <bits/stdc++.h> 
using namespace std;

vector<int> getfreq(string s) {
	vector<int> res(26);
	for (auto i : s) {
		++res[i - 'a'];
	}
	return res;
}

int getinv(string s) {
	int res = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = i + 1; j < (int)s.size(); ++j) {
			res += (s[j] < s[i]);
		}
	}
	return res;
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	vector<int> cnts = getfreq(s);
	vector<int> cntt = getfreq(t);

	if (cnts != cntt) {
		cout << "NO" << '\n';
	} else if (*max_element(cnts.begin(), cnts.end()) > 1 || *max_element(cntt.begin(), cntt.end()) > 1) {
		cout << "YES" << '\n';
	} else {
		cout << (getinv(s) % 2 == getinv(t) % 2 ? "YES" : "NO") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}