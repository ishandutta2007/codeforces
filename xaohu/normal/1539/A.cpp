#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

int T;
long long n, x, t;

void solve() {
	cin >> n >> x >> t;
	t /= x;
	if (t >= n)
		cout << n * (n - 1) / 2 << endl;
	else
		cout << t * (t - 1) / 2 + (n - t) * t << endl;
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}