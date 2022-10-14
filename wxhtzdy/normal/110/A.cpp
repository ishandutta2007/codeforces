#include <bits/stdc++.h>

using namespace std;

bool lucky(int n) {
	if (n == 0) {
		return false;
	}
	int x = n;
	bool ok = true;
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7) {
		 	ok = false;
		 	break;
		}
		x /= 10;
	}
	return ok;
}

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] == '4' || s[i] == '7') {
			cnt++;
		}
	}
	if (lucky(cnt) == true) {
	 	cout << "YES";
	} else {
	 	cout << "NO";
	}
}