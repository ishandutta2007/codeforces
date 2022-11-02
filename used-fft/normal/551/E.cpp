#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define sp << ' ' <<
#define nl << '\n'
 
const int LIM = 5e5, B = 1025, NB = LIM / B + 5;
ll INF = 1e18;
 
int n, q;
ll a[LIM];
set<pair<ll, int>> s[NB];
ll toAdd[NB];
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> q;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		s[i / B].insert({a[i], i});
	}
 
	int t, l, r;
	ll x;
	while(q--) {
		cin >> t;
 
		if(t & 1) {
			cin >> l >> r >> x;
			--l, --r;
 
			for(int i = l; i <= r; ) {
				if(!(i % B) && i + B - 1 <= r) {
					toAdd[i / B] += x;
					i += B;
				} else {
					s[i / B].erase({a[i], i});
					a[i] += x;
					s[i / B].insert({a[i], i});
					i += 1;
				}
			}
		} else {
			cin >> x;
 
			int L = LIM, R = -LIM;
 
			for(int i = 0; i < NB; ++i) {
				auto f = s[i].lower_bound({x - toAdd[i], 0});
 
				if(f != end(s[i]) && f->first == x - toAdd[i]) {
					L = min(L, f->second);
					R = max(R, prev(s[i].lower_bound({x - toAdd[i] + 1, 0}))->second);
				}
			}
 
			if(R < 0) cout << -1 nl;
			else cout << (R - L) nl;
		}
	}
}