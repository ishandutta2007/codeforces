#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t;
ll n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 2050) {
			cout << -1 << endl;
		}
		else {
			n /= 2050;
			int res = 0;
			while (n) {
				res += n % 10;
				n /= 10;
			}
			cout << res << endl;
		}
	}
	return 0;
}