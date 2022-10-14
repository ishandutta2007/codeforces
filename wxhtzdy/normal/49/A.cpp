#include <bits/stdc++.h>

using namespace std;

vector<char> v = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	char a;
	for (int i = 0; i < (int) s.length(); i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
			a = s[i];
		}
	}
	for (int i = 0; i < (int) v.size(); i++) {
		if (v[i] == a) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}