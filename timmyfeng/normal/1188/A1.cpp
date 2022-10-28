#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> deg(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		++deg[u];
		++deg[v];
	}

	cout << (count(deg.begin(), deg.end(), 2) ? "NO" : "YES") << "\n";
}