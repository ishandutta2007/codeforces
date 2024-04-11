#include <bits/stdc++.h>
using namespace std;

bool chk(string& a, string& b) {
	bool ok = true;
	for (int i = 0; i < (int)a.size(); ++i) {
		if (a.substr(i, 2) == b) {
			ok = false;
		}
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> perms;
	string cur = "abc";
	do {
		perms.push_back(cur);
	} while (next_permutation(cur.begin(), cur.end()));

	int n;
	string s, t;
	cin >> n >> s >> t;
	for (auto& p : perms) {
		string res = n > 1 ? p + p : p;
		if (chk(res, s) && chk(res, t)) {
			cout << "YES" << '\n';
			for (int i = 0; i < n; ++i) {
				cout << p;
			}	
			cout << '\n';
			return 0;
		}

		res = "";
		for (auto c : p) {
			if (n > 1) {
				res += c;
			}
			res += c;
		}
		if (chk(res, s) && chk(res, t)) {
			cout << "YES" << '\n';
			for (auto c : p) {
				cout << string(n, c);
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}