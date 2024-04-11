#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(),x.end()
#define sz(x) (int(x.size()))
#define rall(x) x.rbegin(),x.rend()
#define ar array
#define pb push_back
#define lb lower_bound
#define ub upper_bound


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(auto &i : a)
		cin >> i;

	vector<ll> pref(n);
	pref[0] = a[0];
	for(int i = 1; i < n; i++) {
		pref[i] = a[i] + pref[i - 1];
	}

	auto query = [&](int x, int y) -> ll {
		return (x == 0 ? pref[y] : pref[y] - pref[x - 1]);
	};

	vector<ll> newpref(n);
	vector<int> b = a;
	sort(b.begin(), b.end());
	newpref[0] = b[0];
	for(int i = 1; i < n; i++) {
		newpref[i] = newpref[i - 1] + b[i];
	}

	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << query(l, r);
		} else {
			int x, y;
			cin >> x >> y;
			--x, -- y;
			cout << (x == 0 ? newpref[y] : newpref[y] - newpref[x - 1]);
		}
		cout << "\n";
	}
}

//#define LETSGOGOGO 0
int main() {
	int t = 1;
#ifdef LETSGOGOGO
	cin >> t;
#endif

	for(int test_case = 0; test_case < t; test_case++)
		solve();
}