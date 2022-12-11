#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int pref[s.size() + 1];
	pref[0] = 0;
	for (int i = 0; i < s.size(); i++) {
		pref[i + 1] = pref[i];
		if (s[i] == 'a') {
			pref[i + 1]++;
		}
	}
	int n = pref[s.size()], ans = -1;
	for (int i = 0; i <= s.size(); i++) {
		for (int j = i; j <= s.size(); j++) {
			ans = max(ans, pref[i] + (n - pref[j]) + (j - i - (pref[j] - pref[i])));
		}
	}
	cout << ans << endl;
	return 0;
}