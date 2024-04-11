#include <iostream>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = 0;
		while ((i + 1 < s.size()) && (s[i] > s[i + 1])) ++i;
		string pref = s.substr(0, i + 1);
		string res1 = pref + string(pref.rbegin(), pref.rend());

		while ((i + 1 < s.size()) && (s[i] >= s[i + 1])) ++i;
		pref = s.substr(0, i + 1);
		string res2 = pref + string(pref.rbegin(), pref.rend());

		string res = min(res1, res2);
		cout << res << "\n";
	}
	return 0;
}