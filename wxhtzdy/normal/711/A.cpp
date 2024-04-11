#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;                            
	vector<string> s(n);
	bool ok = false;
	for (int i = 0; i < n; i++) {
	 	cin >> s[i];
	 	if (ok == true) {
	 	 	continue;
	 	}
	 	if (s[i][0] == 'O' && s[i][1] == 'O') {
	 	 	ok = true;
	 	 	s[i][0] = '+';
	 	 	s[i][1] = '+';
	 	} else {
	 	 	if (s[i][3] == 'O' && s[i][4] == 'O') {
	 	 	 	ok = true;
	 	 	 	s[i][3] = '+';
	 	 	 	s[i][4] = '+';
	 	 	}
	 	}
	}
	if (ok == false) {
	 	cout << "NO";
	 	return 0;
	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n'; 	
	}
}