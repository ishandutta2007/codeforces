#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int t, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		map<int, long long> m;
		rep(i, 1, n) {
			int x;
			cin >> x;
			ans += m[x] * (n - i + 1);
			m[x] += i;
		}
		cout << ans << "\n";
	}
	return 0;
}