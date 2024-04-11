#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		int a[m]; for(int &i : a) cin >> i;
		sort(a, a + m);

		int b[m];

		for(int i = 1; i < m; ++i)
			b[i] = a[i] - a[i-1];

		b[0] = (n + a[0]) - a[m-1];

		sort(b, b + m);

		int cur {}, ans {};

		for(int i = m; i--; ) { 
			--b[i];
			b[i] -= cur + cur;
			if(b[i] <= 0) break;

			if(b[i] == 1) {
				++ans;
				++cur;
			} else {
				ans += b[i] - 1;
				cur += 2;
			}
		}

		cout << n-ans << '\n';
	}
}