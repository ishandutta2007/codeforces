#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;
 
int T, n, a[123]; 
 
void solve() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	int x = find(a + 1, a + n + 1, *min_element(a + 1, a + n + 1)) - a;
	int y = find(a + 1, a + n + 1, *max_element(a + 1, a + n + 1)) - a; 
	if (x > y) swap(x, y);
	cout << min({y, n - x + 1, x + (n - y + 1)}) << endl;
}
 
int main() {
	cin >> T;
	while (T--)
		solve();
	return 0;
}