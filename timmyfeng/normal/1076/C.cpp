#include <bits/stdc++.h> 
using namespace std;

const double EPS = 1e-9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (!n) {
			cout << 'Y' << ' ' << 0 << ' ' << 0 << '\n';
			continue;
		}

		double lb = EPS, rb = sqrt(n);
		while (rb - lb > EPS) {
			double mb = (lb + rb) / 2;
			if (mb + n / mb > n) {
				lb = mb + EPS;
			} else {
				rb = mb;
			}
		}
		if (abs(lb + n / lb - n) > 1e-6) {
			cout << 'N' << '\n';
		} else {
			cout << 'Y' << ' ' << lb << ' ' << n / lb << '\n';
		}
	}
}