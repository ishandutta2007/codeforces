#include <bits/stdc++.h>

using namespace std;

int t, a, b, k;

long long f(int n) {
	map<int, int> m;
	long long res = 0;
	while (n--) {
		int x;
		cin >> x;
		res += m[x]++;
	}
	return res;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		cout << 1ll * k * (k - 1) / 2 - f(k) - f(k) << "\n";
	}
	return 0;
}