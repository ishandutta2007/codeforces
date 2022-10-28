#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long tot = 0;
	vector<long long> a(n);
	for (auto& i : a) {
		cin >> i;
		tot += i;
	}

	long long ans = 0;
	long long need = 0;
	for (int i = n - 1; i >= 0; --i) {
		long long lb = 0;
		long long rb = a[i] / 2;
		while (lb <= rb) {
			long long mb = (lb + rb) / 2;
			if (tot - mb * 2 >= need + mb) {
				lb = mb + 1;
			} else {
				rb = mb - 1;
			}
		}
		ans += rb;
		need = max(0LL, need + rb - (a[i] - rb * 2));
		tot -= a[i];
	}

	cout << ans << "\n";
}