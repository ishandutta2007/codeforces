#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int dp_dislike[3001][3001];
int dp_like[3001][3001];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int mod_inv(int a) {
	return mod_pow(a, M - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int init_like = 0;
	int init_dislike = 0;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		if (a[i]) {
			init_like += w[i];
		} else {
			init_dislike += w[i];
		}
	}

	for (int i = m; i >= 0; --i) {
		for (int j = min(m, init_dislike); j >= 0; --j) {
			int like = init_like + i;
			int dislike = init_dislike - j;

			if (i + j >= m) {
				dp_like[i][j] = like;
				dp_dislike[i][j] = dislike;
			} else {
				int den = mod_inv(like + dislike);

				dp_like[i][j] = add(
						mul(mul(like, den), dp_like[i + 1][j]),
						mul(mul(dislike, den), dp_like[i][j + 1])
				);

				dp_dislike[i][j] = add(
						mul(mul(like, den), dp_dislike[i + 1][j]),
						mul(mul(dislike, den), dp_dislike[i][j + 1])
				);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			cout << mul(mul(w[i], mod_inv(init_like)), dp_like[0][0]) << "\n";
		} else {
			cout << mul(mul(w[i], mod_inv(init_dislike)), dp_dislike[0][0]) << "\n";
		}
	}
}