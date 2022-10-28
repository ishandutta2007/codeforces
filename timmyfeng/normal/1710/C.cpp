#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

int main() {
	string n; cin >> n;
	reverse(n.begin(), n.end());

	long long w = 1, s = 1, x = 1, p3 = 1, p2 = 1;
	for (auto d : n) {
		if (d == '0') {
			s = 2 * s % M;
		} else {
			w = (s + w + (p3 * p2 % M + p2) * (M + 1) / 2 + x * p3) % M;
			x = (x + p2) % M;
			s = (2 * s + 2 * x * p3) % M;
		}
		p3 = 3 * p3 % M, p2 = 2 * p2 % M;
	}

	cout << ((x * (x - 1) % M * (x - 2) - 6 * (w - x - x * (x - 1))) % M + M) % M << "\n";
}