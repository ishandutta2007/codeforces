#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int bal = 0, mx = 0;
	for (int i = 0; i < n; i++) {
	 	int a, b;
	 	cin >> a >> b;
	 	bal -= a; bal += b;
	 	mx = max(mx, bal);
	}
	cout << mx;
}