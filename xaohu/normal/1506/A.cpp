#include <bits/stdc++.h>

using namespace std;

long long t, n, m, x;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> x;
		x--;
		int c = x / n;
		int r = x % n;
		cout << r * m + c + 1 << "\n";
	}
}