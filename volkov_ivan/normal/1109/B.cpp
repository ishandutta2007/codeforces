#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool check(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return (s == t);
}

int main() {
	string s;
	cin >> s;
	int l = 0, r = ((int) s.length()) - 1;
	set <char> all;
	while (l < r) {
		all.insert(s[l]);
		all.insert(s[r]);
		l++;
		r--;
	}
	if (all.size() <= 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 0; i < ((int) s.length()) - 1; i++) {
		string fi = "", se = "";
		for (int j = 0; j <= i; j++) fi += s[j];
		for (int j = i + 1; j < (int) s.length(); j++) se += s[j];
		if (check(se + fi)  && (se + fi != s)) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}