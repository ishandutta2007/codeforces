#include <bits/stdc++.h>
using namespace std;
int main() {
	int qq;
	cin >> qq;
	int x = 0;
	while (qq--) {
		string s;
		cin >> s;
		int o = 0;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '+') {
				o = 1;
			} else {
				if (s[i] == '-') {
					o = 2;
				}
			}
		}
		if (o == 2) {
			x--;
		} else {
			x++;
		}
	}
	cout << x << endl;
}