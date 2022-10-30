#include <bits/stdc++.h>
using namespace std;

char f;
string s;

int main() {
	cin >> f >> s;
	bool bad = 1;
	for (char c: s) if (islower(c)) bad = 0;
	if (bad) {
		if (isupper(f)) cout << (char) (f-'A'+'a');
		else cout << (char) (f-'a'+'A');
		for (char c: s) cout << (char) (c-'A'+'a');
	} else cout << f << s;

	return 0;
}