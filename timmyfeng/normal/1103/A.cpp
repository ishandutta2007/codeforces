#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int zero = 0;
	int one = 0;
	for (auto i : s) {
		if (i == '0') {
			cout << 1 << " " << zero + 1 << "\n";
			zero = (zero + 1) % 4;
		} else {
			cout << 3 << " " << one + 1 << "\n";
			one = (one + 2) % 4;
		}
	}
}