#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
int n, q;
int cnt[100];
 
void solve() {
	cin >> n >> q;
	for(int i = 0; i < n; ++ i) cin >> cnt[i];
	for(; q --;) {
		int ty, pos;
		ll val;
		cin >> ty >> pos >> val;
		if (ty == 1) {
			cnt[pos] = val;
		} else {
			ll now = 0, cur = 0;
			for (int i = 0; i <= pos; ++ i) {
				now += cnt[i] * ((1ll << i) - 1);
				val -= cnt[i];
			}
			if (val <= 0) {
				puts("0");
				continue;
			}
 
			int id = pos + 1;
			while (id < n) {
				ll add = 1ll << (id - pos);
				ll need = min(val / add, (long long)cnt[id]);
				cur += need * (add - 1);
				val -= need * add;
				now += need * add * ((1ll << pos) - 1);
 
				if (need == cnt[id])
					id++;
				else
					break;
			}
			if (val == 0) {
				cout << cur << endl;
				continue;
			}
			if (id >= n) {
				cout << (val > now ? -1 : cur + val) << endl;
				continue;
			}
 
			long long ans = 1e18;
			while (id > pos) {
				if (now >= val)
					ans = min(ans, cur + val);
				cur++;
				id--;
				long long add = 1ll << (id - pos);
				if (val >= add) {
					cur += add - 1;
					val -= add;
					now += add * ((1ll << pos) - 1);
				}
			}
			assert(val <= 0);
			cout << min(ans, cur) << endl;
		}
	}
}
int main() {
		solve();
    return 0;
}