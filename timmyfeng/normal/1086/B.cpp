#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int n, s;
	cin >> n >> s;

	vector<int> degree(n + 1);
	for (int i = 0; i < (n - 1) * 2; ++i) {
		int u;
		cin >> u;
		++degree[u];
	}

	if (n == 2) {
		cout << s << "\n";
		exit(0);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += (degree[i] == 1);
	}

	cout << 2.0 * s / cnt << "\n";
}