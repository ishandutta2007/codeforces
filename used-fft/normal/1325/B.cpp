#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		set<int> a;
		while(n--) {
			int v; cin >> v;
			a.insert(v);
		}
		cout << size(a) << '\n';
	}
}