#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
using namespace std;
typedef long long ll;

int q, a, b;

void solve() {
	cin >> a >> b;
	int s = 0, ans = (a <= b);
	rep(i, 0, 30) {
		s += a >> i & 1;
		s -= b >> i & 1;
		if (s < 0) ans = 0;
	}
	cout << (ans ? "YES\n" : "NO\n");
}

int main() {
	cin >> q;
	while (q--) 
		solve();
	return 0;
}