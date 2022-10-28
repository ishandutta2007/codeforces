#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<int> freq(m);
	for (auto& i : a) {
		cin >> i;
		for (int j = 0; j < m; ++j) {
			if (i[j] == '1') {
				++freq[j];
			}
		}
	}

	for (auto& i : a) {
		bool ok = true;
		for (int j = 0; j < m; ++j) {
			ok &= (i[j] == '0' || freq[j] > 1);
		}
		if (ok) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}