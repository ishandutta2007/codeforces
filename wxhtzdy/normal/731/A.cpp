#include <bits/stdc++.h>

using namespace std;

int main() {     
	string s;
	cin >> s;
	char a = 'a';
	int res = 0;
	for (int i = 0; i < (int) s.length(); i++) {
	 	res += min(abs((int) (a - s[i])), 26 - (int)abs((int) (a - s[i])));   
		a = s[i];
	}
	cout << res;
}