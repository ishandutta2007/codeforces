#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int jump[100001][26][2], lst[26][2];
int T, n;
string s, t;

bool solve(int a) {
	int m = t.length();
	for (int i = 0; i + 1 < m; i++) {
		a = jump[a][t[i + 1] - 'a'][!(a % 2)];
	}
	return (a < n && a % 2 != n % 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> s >> t;
		n = s.length();

		for (int i = 0; i < 26; i++)
			lst[i][0] = lst[i][1] = jump[n][i][0] = jump[n][i][1] = n;

		for (int i = n - 1; 0 <= i; i--) {
			for (int c = 0; c < 26; c++) 
				for (int j = 0; j < 2; j++)
					jump[i][c][j] = lst[c][j];
			lst[s[i] - 'a'][i % 2] = i;
		}
		
		int cnt[2]{};
		bool ok = 0;

		for (int i = 0; i < n; i++)
			if (s[i] == t[0] && !cnt[i % 2]) {
				cnt[i % 2]++;
				ok |= solve(i);
			}

		cout << (ok ? "YES\n" : "NO\n");
	}
}