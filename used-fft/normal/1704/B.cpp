#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, x; cin >> n >> x;

		int ans {}, l, r;
		cin >> l;
		r = l;

		for(int i = 1; i < n; ++i) {
			int v; cin >> v;
			l = min(l, v);
			r = max(r, v);

			if(r - l > 2*x) {
				++ans;
				l = r = v;
			}
		}
		cout << ans << '\n';
	}
}