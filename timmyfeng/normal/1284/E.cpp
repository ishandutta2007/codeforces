#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pt = complex<ll>;
#define x real()
#define y imag()

ll cross(pt p, pt q) {
	return (conj(p) * q).y;
}

bool half(pt p) {
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

ll cnk(int n, int k) {
	ll res = 1;
	for (int i = 0; i < k; ++i) {
		res *= n - i;
		res /= i + 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pt> pts;
	for (int i = 0; i < n; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		pts.emplace_back(xi, yi);
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		vector<pt> vecs;
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				vecs.push_back(pts[j] - pts[i]);
			}
		}
		sort(vecs.begin(), vecs.end(), [](pt a, pt b) {
			return make_pair(half(a), 0LL) < make_pair(half(b), cross(a, b));
		});

		int k = 1;
		int m = vecs.size();
		for (int j = 0; j < m; ++j) {
			while (half(conj(vecs[j]) * vecs[k])) {
				k = (k + 1) % m;
			}
			sum += cnk((k - j - 1 + m) % m, 3);
		}
	}
	cout << 5 * cnk(n, 5) - sum << '\n';
}