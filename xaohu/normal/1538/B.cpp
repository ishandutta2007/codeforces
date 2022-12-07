#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, n, a[231231];
 
void solve() {
	int s = 0;
	cin >> n;
	rep(i, 1, n) cin >> a[i], s += a[i];
	if (s % n) return cout << "-1\n", void(0);
	int res = 0;
	rep(i, 1, n) if (a[i] > s / n) res++;
	cout << res << endl;
}  
 
int main() {
	cin >> T;
	while (T--) solve();
	return 0;
}