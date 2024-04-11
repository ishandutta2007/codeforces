#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, n, a[1 << 18];

void solve() {
	cin >> n;
	rep(i, 0, n) 
		cin >> a[i];
	rep(i, 0, n - 1)
		if (abs(a[i] - a[i + 1]) >= 2) {
			cout << "YES\n" << i + 1 << " " << i + 2 << "\n";
			return;
		}
	cout << "NO\n";
}	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--)
		solve();
	return 0;
}