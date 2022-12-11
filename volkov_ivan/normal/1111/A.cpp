#include <iostream>

using namespace std;

int is_vowel(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
	return 0;
}

int main() {
	string s, t;
	cin >> s >> t;
	if (s.length() != t.length()) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0; i < (int) s.length(); i++) {
		int d = is_vowel(s[i]) - is_vowel(t[i]);
		if (d != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}