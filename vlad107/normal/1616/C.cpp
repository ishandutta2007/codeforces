#include <iostream>
#include <vector>

using namespace std;

double EPS = 1e-7;

int check(const vector<int> &a, int index, double valA, double valB) {
	int cnt = 0;
	double u = valA;
	double v = valB;
	for (int i = index + 2; i < a.size(); i++) {
		double nextVal = 2 * v - u;
		if (abs(nextVal - a[i]) < EPS) ++cnt;
		u = v; v = nextVal;
	}
	u = valA; v = valB;
	for (int i = index - 1; i >= 0; i--) {
		double nextVal = 2 * u - v;
		if (abs(nextVal - a[i]) < EPS) ++cnt;
		v = u; u = nextVal;
	}
	if (abs(valA - a[index]) < EPS) ++cnt;
	if (abs(valB - a[index + 1]) < EPS) ++cnt;
	return (int)a.size() - cnt;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x: a) cin >> x;
		if (n <= 2) {
			cout << "0\n";
			continue;
		}
		int res = n - 1;
		for (int i = 0; i < n; i++) {
			if (i + 1 < n) {
				res = min(res, check(a, i, a[i], a[i + 1]));
			}
			double ca = 0;
			double cb = 1;
			double cx = 1;
			double cy = 0;
			// a[i] * cx + a'[i + 1] * cy = a'[j - 2]
			// a[i] * ca + a'[i + 1] * cb = a'[j - 1]
			// a'[j] = 2 * a'[j - 1] - a'[j - 2] = a[i] * (2 * ca - cx) + a'[i + 1] * (2 * cb - cy)
			for (int j = i + 2; j < n; j++) {
				double nextA = 2 * ca - cx;
				double nextB = 2 * cb - cy;
				cx = ca; cy = cb;
				ca = nextA; cb = nextB;
				// a[j] = a[i] * ca + a'[i + 1] * cb
				// a'[i + 1] = (a[j] - a[i] * ca) / cb
				if (abs(cb) > EPS) {
					res = min(res, check(a, i, a[i], (a[j] - a[i] * ca) / cb));
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}