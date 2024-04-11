#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> h(n);
	for (auto& i : h) {
		cin >> i;
		i %= a + b;
		if (i == 0) {
			i += a + b;
		}
		i = (i - 1) / a;
	}
	sort(h.begin(), h.end());

	int ans = 0;
	for (auto i : h) {
		if (k - i < 0) break;
		++ans;
		k -= i;
	}
	cout << ans << '\n';
}