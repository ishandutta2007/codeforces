#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int P = 31607;
int n, a[21][21], b[21][21], res = 1;

int mul(int a, int b) {
	return a * b % P;
}

void rec(int x, vector<int> v, int prob, int coef) {
	if (x == n) {
		int p = 1;
		for (int i = 0; i < n; i++)
			p = p * (1 - v[i] + P) % P;
		res = (res + mul(p, prob) * coef + P) % P;
		return;
	}
	vector<int> u = v;
	for (int i = 0; i < n; i++)
		u[i] = mul(u[i], b[x][i]);
	rec(x + 1, u, prob, coef);

	for (int i = 0; i < n; i++)
		prob = mul(prob, b[x][i]);
	rec(x + 1, v, prob, -coef);
}

int main() {
	int inv;
	for (int i = 1; i < P; i++)
		if (mul(i, 10000) == 1)
			inv = i;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = mul(a[i][j], inv);
		}

	for (int d1 : {0, 1})
		for (int d2 : {0, 1}) {
			memcpy(b, a, sizeof b);
			int prob = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if ((d1 && i == j) || (d2 && n - 1 - i == j)) {
						prob = mul(prob, b[i][j]);
						b[i][j] = 1;
					}

			rec(0, vector<int>(n, 1), prob, (d1 + d2) % 2 ? 1 : -1);
		}

	cout << res << endl;
	return 0;
}