#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n, m;
string a, b;

string solve(int st, int x) {
	string res;
	if (st + x > n)
		return res;
	for (int i = st; i < st + x; i++)
		res += a[i];
	for (int i = st + x - 2; i >= max(0, st + x - 1 - (m - x)); i--)
		res += a[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		bool ok = 0;
		n = a.size();
		m = b.size();
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
				if (solve(i, j) == b)
					ok = 1;
		cout << (ok ? "YES\n" : "NO\n");
	}
}