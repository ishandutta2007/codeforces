#include <bits/stdc++.h>
using namespace std;
vector<int> col, t;
int n;

void dfs(int a, int c) {
	col[a] = c;
	int i = (a + 1) % n;
	int j = (a - 1 + n) % n;
	if (col[i] && col[j] && t[i] != t[a] && t[j] != t[a] && col[i] != col[j]) {
		col[a] = 3;
		return;
	}
	for (auto k : {i, j}) {
		if (t[k] == t[a]) continue;
		if (!col[k]) {
			dfs(k, 3 - c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int _t;
	cin >> _t;
	while (_t--) {
		cin >> n;
		t.resize(n);
		for (auto& i : t) {
			cin >> i;
		}
		col.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			if (!col[i]) {
				dfs(i, 1);
			}			
		}
		cout << *max_element(col.begin(), col.end()) << '\n';
		for (auto i : col) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}