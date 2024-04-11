#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		string _s; cin >> _s;
#define s(I) (_s[I] == '1')

		int pre[n*m] {}, ans[n*m] {};
		pre[0] = s(0);
		for(int i = 1; i < n*m; ++i)
			pre[i] = pre[i-1] + s(i);

		int last = -n*m-100, cnt {}, add[m] {};

		for(int i = 0; i < n*m; ++i) {
			if(s(i) && last + m < i)
				++add[i % m];
			if(s(i)) last = i;

			if(i >= m && s(i-m) && pre[i] == pre[i-m])
				--add[i % m];

			cnt += add[i % m];
			ans[i] = cnt;
		}

		fill(add, add+m, 0); cnt = 0;
		for(int i = 0; i < n*m; ++i) {
			if(s(i))
				cnt += !add[i % m]++;
			cout << ans[i] + cnt << ' ';
		}
		cout << '\n';
	}
}