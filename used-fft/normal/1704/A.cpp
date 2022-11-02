#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;

		if(m > n) {
			cout << "NO\n";
			continue;
		}

		bool ok = 1;
		for(int i = 1; i < m; ++i)
			if(b[m-i] != a[n-i]) ok = 0;

		bool f = 0;

		for(int i = n-m; i >= 0; --i)
			if(a[i] == b[0]) f = 1;

		cout << (f && ok ? "YES" : "NO") << "\n";
	}
}