#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		int c[2] {};
		while(m--) {
			for(int j : {0, 1}) {
				int v; cin >> v;
				c[j] = max(c[j], v);
			}
		}
		if(c[0] + c[1] > n) {
			cout << "IMPOSSIBLE\n";
		} else {
			c[1] = max(c[1], n - c[0]);
			while(c[0]--) cout << 'R';
			while(c[1]--) cout << 'W';
			cout << '\n';
		}
	}
}