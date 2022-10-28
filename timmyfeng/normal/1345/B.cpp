#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	auto calc = [](int a) {
		return (long long)a * (a - 1) / 2 * 3 + 2 * a;
	};
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		while (n >= 2) {
			++ans;
			int lb = 1, rb = 1e5;
			while (lb < rb) {
				int mb = lb + (rb - lb + 1) / 2;
				if (calc(mb) <= n) {
					lb = mb;
				} else {
					rb = mb - 1;
				}
			}
			n -= calc(lb);
		}
		cout << ans << '\n';
	}
}