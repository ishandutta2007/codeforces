#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int out = 3;
	bool ok = true;
	while (n--) {
		int a;
		cin >> a;
		ok &= (a != out);
		out = 6 - out - a;
	}
	cout << (ok ? "YES" : "NO") << '\n';
}