#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n % 2 == 0) {
			swap(n, m);
			k = n * m / 2 - k;
		}
		if (n % 2 == 0)
			cout << (k % 2 == 0 ? "YES\n" : "NO\n");
		else
			cout << (k >= m / 2 && k % 2 == (m / 2) % 2 ? "YES\n" : "NO\n") << endl;
	}
	return 0;
}