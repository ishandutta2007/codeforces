#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
const int M = (119 << 23) + 1;

int add(int a, int b) {
	int res = a + b;
	return res < M ? res : res - M;
}

int sub(int a, int b) {
	int res = a - b;
	return res < 0 ? res + M : res;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int same[MX], diff[MX];

int solve(vector<int>& a, int k) {
	int n = a.size();
	int res = 1;
	int prev = 0;
	int len = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			++len;
		} else {
			if (!prev) {
				if (len) {
					res = mul(res, add(mul(k - 1, diff[len - 1]), same[len - 1]));
				}
			} else if (prev == a[i]) {
				res = mul(res, same[len]);
			} else {
				res = mul(res, diff[len]);
			}
			prev = a[i];
			len = 0;
		}
	}

	if (len) {
		if (prev) {
			res = mul(res, add(mul(k - 1, diff[len - 1]), same[len - 1]));
		} else {
			if (len == 1) {
				res = k;
			} else {
				res = add(mul(k, same[len - 2]), mul(mul(k, k - 1), diff[len - 2]));
			}
		}
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		(i % 2 ? odd : even).push_back(a);
	}

	diff[0] = 1;
	for (int i = 1; i < n; ++i) {
		same[i] = mul(k - 1, diff[i - 1]);
		diff[i] = add(mul(k - 2, diff[i - 1]), same[i - 1]);
	}

	cout << mul(solve(even, k), solve(odd, k)) << '\n';
}