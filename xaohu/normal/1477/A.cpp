#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int T, n;
ll k, a[222000];
 
void solve() {
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll g = 0;
	rep(i, 2, n) g = __gcd(g, a[i] - a[1]);
	cout << (abs(k - a[1]) % g ? "NO\n" : "YES\n");
} 
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}