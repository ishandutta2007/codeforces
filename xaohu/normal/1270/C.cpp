#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, n, a;

void solve() {
	ll s = 0, x = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		s += a;
		x ^= a;
	}
	cout << 2 << "\n" << x << " " << s + x << "\n";
}	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--)
		solve();
	return 0;
}