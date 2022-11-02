#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		int x = -1;
		for(int i = 0; i < n; ++i) {
			int v; cin >> v;
			if(v != i) {
				if(x < 0) x = v;
				else x = x & v;
			}
		}
		cout << x << '\n';
	}
}