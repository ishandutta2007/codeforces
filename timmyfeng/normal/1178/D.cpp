#include <bits/stdc++.h>
using namespace std;

const int MX = 2001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> sieve(MX);
	for (int i = 2; i < MX; ++i) {
		if (!sieve[i]) {
			for (int j = i * 2; j < MX; j += i) {
				sieve[j] = true;
			}
		}
	}

	int n;
	cin >> n;

	int m = n;
	while (sieve[m]) {
		++m;
	}

	cout << m << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << i << " " << i % n + 1 << "\n";
	}
	for (int i = 1; n + i <= m; ++i) {
		cout << i << " " << i + n / 2 << "\n";
	}
}