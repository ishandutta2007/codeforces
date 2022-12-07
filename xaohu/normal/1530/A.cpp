#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int res = 0;
		while (n) {
			res = max(res, n % 10);
			n /= 10;
		}
		cout << res << endl;
	}
	return 0;
}