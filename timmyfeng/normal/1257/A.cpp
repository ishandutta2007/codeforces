#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		cout << min(n - 1, b - a + x) << '\n';
	}
}