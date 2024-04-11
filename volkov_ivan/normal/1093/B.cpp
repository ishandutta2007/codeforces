#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		char ch = s[0], flag = 1;
		for (int j = 1; j < (int) s.length(); j++) {
			if (s[j] != ch) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "-1" << endl;
			continue;
		}
		sort(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}