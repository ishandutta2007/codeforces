#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

int t, n, k;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> k;
		while (k > 3) {
			cout << 1 << " ";
			n--; k--;
		}
		if (__builtin_popcount(n) == 1) {
			cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
			continue;
		}
		int a = 1, b, c;
		while (n % 2 == 0) {
			a *= 2;
			n /= 2;
		}
		b = c = a;
		a = b = a * (n / 2);
		cout << a << " " << b << " " << c << "\n";
	}
	return 0;
}