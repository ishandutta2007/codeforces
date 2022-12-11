#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	for (int i = 0; i < t; i++) {
		cin >> s;
		int sm = -1, b = -1, n = -1;
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 'a' && s[j] <= 'z' && sm == -1) sm = j, cnt++;
			if (s[j] >= 'A' && s[j] <= 'Z' && b == -1) b = j, cnt++;
			if (s[j] >= '0' && s[j] <= '9' && n == -1) n = j, cnt++;
		}
		if (sm != -1 && b != -1 && n != -1) {
			cout << s << endl;
			continue;
		}
		if (cnt == 1) {
			if (sm != -1) s[0] = 'A', s[1] = '0';
			if (b != -1) s[0] = 'a', s[1] = '0';
			if (n != -1) s[0] = 'A', s[1] = 'a';
			cout << s << endl;
		} else {
			int pos = -1;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] >= 'a' && s[j] <= 'z' && sm != j) {
					pos = j;
					break;
				}
				if (s[j] >= 'A' && s[j] <= 'Z' && b != j) {
					pos = j;
					break;
				}
				if (s[j] >= '0' && s[j] <= '9' && n != j) { 
					pos = j;
					break;
				}
			}
			if (sm == -1) s[pos] = 'a';
			if (n == -1) s[pos] = '0';
			if (b == -1) s[pos] = 'A';
			cout << s << endl;
		}

	}
	return 0;
}