#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	string s;
	cin >> n >> s;
	cin >> s;
	if (s[0]=='w') {
		if (n==5 || n==6) cout << 53;
		else cout << 52;
	} else {
		if (n<=29) cout << 12;
		else if (n<=30) cout << 11;
		else cout << 7;
	}

	return 0;
}