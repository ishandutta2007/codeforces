#include <bits/stdc++.h>

using namespace std;

int t, n;
string s[405];

int f(int x) {
	return x == 0 ? 1 : x - 1;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int a1 = -1, b1, a2, b2;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < n; j++)
				if (s[i][j] == '*') {
					if (a1 == -1)
						a1 = i, b1 = j;
					else
						a2 = i, b2 = j;
				}
		}
		if (a1 == a2) 
			s[f(a1)][b1] = s[f(a2)][b2] = '*';
		else if (b1 == b2)
			s[a1][f(b1)] = s[a2][f(b2)] = '*';
		else
			s[a1][b2] = s[a2][b1] = '*';
		for (int i = 0; i < n; i++) 
			cout << s[i] << "\n";
	}
	return 0;
}