#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int> M, T;
		FOR(i, n)
			(s[i] == 'M' ? M : T).push_back(i);
		bool ok = (M.size() == n / 3);
		if (ok) 
			FOR(i, n / 3) 
				ok &= T[i] < M[i] && M[i] < T[n / 3 + i];
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}