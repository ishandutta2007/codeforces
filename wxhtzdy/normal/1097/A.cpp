#include <bits/stdc++.h>

using namespace std;

int main() {              
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 0; i < 5; i++) {
	 	string a;
	 	cin >> a;
	 	if (a[0] == s[0] || a[1] == s[1]) {
	 	 	ok = true;
	 	}
	}
	cout << (ok ? "YES" : "NO");
}