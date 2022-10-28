#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b) {
			swap(a, b);
		}
		int d = c - r;
		int e = c + r;
		int sol = b - a;
		int cvr = min(e, b) - max(d, a);
		if (cvr > 0) {
			sol -= cvr;
		}
		cout << sol << "\n";
	}
}