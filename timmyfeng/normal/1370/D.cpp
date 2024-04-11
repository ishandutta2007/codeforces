#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int lb = 1, rb = 1e9;
	while (lb <= rb) {
		int mb = (lb + rb) / 2;
		bool ok = false;

		int cnt = 0;
		for (int i = 0; i < n - !(k % 2); ++i) {
			if (a[i] <= mb) {
				++cnt;
				++i;
			}
		}
		ok |= (cnt >= (k + 1) / 2);

		cnt = 0;
		for (int i = 1; i < n - k % 2; ++i) {
			if (a[i] <= mb) {
				++cnt;
				++i;
			}
		}
		ok |= (cnt >= k / 2);

		if (ok) {
			rb = mb - 1;
		} else {
			lb = mb + 1;
		}
	}
	cout << lb << "\n";
}