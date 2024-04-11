#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int T, n, k1, k2,  w, b;
 
void solve() {
	cin >> n >> k1 >> k2 >> w >> b;
	cout << (2 * w <= k1 + k2 && 2 * b <= (n - k1 + n - k2) ? "YES\n" : "NO\n");
}
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}