#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		map<int, int> c;
		while(n--) {
			int v; cin >> v;
			++c[v];
		}

		int a[2] {};
		for(auto &[i, j] : c)
			a[j > 1]++;

		if(a[0]) {
			++a[1];
			--a[0];
		}

		cout << (a[1] + a[0] / 2) << '\n';
	}
}