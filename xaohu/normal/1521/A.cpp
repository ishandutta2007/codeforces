#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++) 

using namespace std;

long long t, a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (b == 1) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n" << a * b << " " << a << " " << a * (b + 1) << "\n";
		}
	}
}