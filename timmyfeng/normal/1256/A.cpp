#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, s;
		cin >> a >> b >> n >> s;
		b -= s % n;
		s = s - s % n;
		if (b < 0) {
			cout << "NO" << '\n';
			continue;
		}
		a += b / n;
		cout << (s / n <= a ? "YES" : "NO") << '\n';
	}
}