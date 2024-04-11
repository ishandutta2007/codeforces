#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int lb = a * n - b * n;
		int ub = a * n + b * n;
		cout << (ub < c - d || lb > c + d ? "No" : "Yes") << '\n';
	}
}