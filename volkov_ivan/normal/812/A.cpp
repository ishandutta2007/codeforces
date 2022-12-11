#include <iostream>

using namespace std;

int main() {
	bool ans = false;
	bool l[4], s[4], r[4], p[4];
	for (int i = 0; i < 4; i ++) {
		cin >> l[i] >> s[i] >> r[i] >> p[i];
	}
	ans = ans || (p[0] && (s[0] || l[0] || r[0] || l[1] || s[2] || r[3]));
	ans = ans || (p[1] && (s[1] || l[1] || r[1] || l[2] || s[3] || r[0]));
	ans = ans || (p[2] && (s[2] || l[2] || r[2] || l[3] || s[0] || r[1]));
	ans = ans || (p[3] && (s[3] || l[3] || r[3] || l[0] || s[1] || r[2]));
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}