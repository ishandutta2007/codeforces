#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		cout << b + mx << ' ';
		mx = max(mx, b + mx);
	}
}