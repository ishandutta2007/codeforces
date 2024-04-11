#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a].push_back(i);
	}

	int cur = 1;
	vector<string> ans(n + 1, string(n, '0'));
	for (int i = n; i; --i) {
		for (auto j : pos[i]) {
			for (int k = 0; k < i; ++k) {
				ans[(cur + k) % (n + 1)][j] = '1';
			}
			++cur;
		}
	}

	cout << n + 1 << "\n";
	for (auto& i : ans) {
		cout << i << "\n";
	}
}