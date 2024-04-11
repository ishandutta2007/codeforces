#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = (int) s.length();
		vector< pair<int, int> > v;
		for (int i = 0; i < n; i++) {
			if (s[i] != '0') {
				v.push_back(make_pair((int)(s[i] - '0'), n - i - 1));
			}
		}
		cout << (int)v.size() << endl;
		for (int i = 0; i < (int)v.size(); i++) {
			cout << v[i].first;
			for (int j = 0; j < v[i].second; j++) {
				cout << 0;
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}