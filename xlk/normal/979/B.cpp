#include <bits/stdc++.h>
using namespace std;
int n;
int c[256];
int get() {
	memset(c, 0, sizeof c);
	string s;
	cin >> s;
	int z = 0;
	for (int i = 0; i < s.size(); i++) {
		c[s[i]]++;
		z = max(z, c[s[i]]);
	}
	if (s.size() == 1) {
		return z;
	}
	if (n == 1 && z == s.size()) {
		return z - 1;
	}
	return min(z + n, (int)s.size());
}
int main() {
	cin >> n;
	vector<pair<int, string> > a;
	a.push_back(make_pair(get(), "Kuro"));
	a.push_back(make_pair(get(), "Shiro"));
	a.push_back(make_pair(get(), "Katie"));
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	if (a[0].first == a[1].first) {
		cout << "Draw" << endl;
	} else {
		cout << a[0].second << endl;
	}
	return 0;
}