#include <bits/stdc++.h>

using namespace std;

int t, n, a;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, vector<int>> m;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			m[a].push_back(i);
		}
		for (auto [e, vec] : m)
			if (vec.size() == 1)
				cout << vec[0] << "\n";
	}
	return 0;
}