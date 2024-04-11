#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (auto& i : s) {
		cin >> i;
	}
	for (auto& i : t) {
		cin >> i;
	}

	int q;
	cin >> q;
	while (q--) {
		int y;
		cin >> y;
		--y;
		cout << s[y % n] << t[y % m] << '\n';
	}
}