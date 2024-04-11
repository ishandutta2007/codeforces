#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool t[26];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	memset(t, false, sizeof(t));
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s.length() > 26) {
			cout << -1 << endl;
			return 0;
		}
		if (t[s[i] - 'a']) {
			cnt++;
		} else {
			t[s[i] - 'a'] = true;
		}
	}
	cout << cnt << endl;
	return 0;
}