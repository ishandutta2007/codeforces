#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == 'v' && s[i] == 'v') {
			a += 1;
			c += b;
		}
		if (s[i] == 'o') {
			b += a;
		}
	}
	cout << c << endl;
	return 0;
}