#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 10;

int t, n;

void read(vector<vector<int>> &x) {
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			x[i][j] = s[j] - '0';
	}
}

bool check(vector<vector<int>> a, vector<vector<int>> b) {
	for (int i = 0; i < n; i++)
		if (a[i][0] != b[i][0])
			for (int j = 0; j < n; j++)
				a[i][j] ^= 1;
	for (int i = 1; i < n; i++) 
		if (a[0][i] != b[0][i])
			for (int j = 0; j < n; j++)
				a[j][i] ^= 1;
	return a == b;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
		read(a); 
		read(b);
		int ok = 0;
		for (int e = 0; e < 2; e++) {
			ok |= check(a, b);
			for (int i = 0; i < n; i++)
				a[i][0] ^= 1;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}