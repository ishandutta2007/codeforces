#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pt = complex<ll>;
#define x real()
#define y imag()

const int MX = 1e5;

pt pts[MX];

ll cross(pt p, pt q) {
	return p.x * q.y - p.y * q.x;
}

ll orient(pt p, pt q, pt r) {
	return cross(q - p, r - p);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		pts[i] = {xi, yi};
	}

	if (n <= 3) {
		cout << "YES" << '\n';
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			vector<bool> covered(n);
			for (int k = 0; k < n; ++k) {
				covered[k] = !orient(pts[i], pts[j], pts[k]);
			}
			
			bool ok = true;
			int oth_i = -1;
			int oth_j = -1;
			for (int k = 0; k < n; ++k) {
				if (covered[k])
					continue;
				if (oth_i == -1) {
					oth_i = k;
				} else if (oth_j == -1) {
					oth_j = k;
				} else {
					ok &= !orient(pts[oth_i], pts[oth_j], pts[k]);
				}
			}

			if (ok) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
}