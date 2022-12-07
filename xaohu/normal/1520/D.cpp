#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n;

int main() {
	cin >> t;
	while (t--) {
		long long ans = 0;
		map<int, int> cnt;
		cin >> n;
		rep(i, 1, n) {
			int x;
			cin >> x;
			ans += cnt[x - i]++;
		}
		cout << ans << "\n";
	}
	return 0;
}