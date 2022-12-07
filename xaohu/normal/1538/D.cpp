#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, a, b, k;

int cnt(int x) {
	int res = 0;
	rep(i, 2, x) {
		if (i * i > x) break;
		while (x % i == 0) {
			x /= i;
			res++;
		}
	}
	if (x > 1) res++;
	return res;
}

void solve() {
	cin >> a >> b >> k;
	if (a > b) swap(a, b);
	if (k == 1) 
		return cout << (a != b && b % a == 0 ? "YES\n" : "NO\n"), void(0);
	cout << ((a != 1) + (b != 1) <= k && k <= cnt(a) + cnt(b) ? "YES\n" : "NO\n");
} 	
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}