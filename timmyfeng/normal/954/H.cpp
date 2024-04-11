#include <bits/stdc++.h> 
using namespace std;

const int MX = 5000 + 1;
const int M = 1e9 + 7;

int a[MX], cnt[MX], dp_up[3][MX], dp_down[3][MX], ans[MX * 2];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
	}

	cnt[0] = 1;
	for (int i = 1; i < n; ++i) {
		cnt[i] = mul(cnt[i - 1], a[i - 1]);
	}

	for (int i = 0; i <= 2 * n - 2; ++i) {
		int ii = i % 3;
		for (int j = 0; j < n; ++j) {
			dp_down[ii][j] = i ? mul(dp_down[(i - 1) % 3][j + 1], a[j]) : 1;

			if (!j) {
				dp_up[ii][j] = 0;
			} else if (i <= 1) {
				dp_up[ii][j] = 1;
			} else {
				dp_up[ii][j] = add(dp_up[(i - 1) % 3][j - 1], mul(dp_down[(i - 2) % 3][j], a[j - 1] - 1));
			}

			if (i) {
				ans[i] = add(ans[i], mul(cnt[j], add(dp_up[ii][j], dp_down[ii][j])));
			}
		}
	}

	for (int i = 1; i <= 2 * n - 2; ++i) {
		cout << mul(ans[i], (M + 1) / 2) << ' ';
	}
	cout << '\n';
}