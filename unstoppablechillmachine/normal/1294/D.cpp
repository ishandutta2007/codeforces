#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q, mod;
	cin >> q >> mod;
	vector<int> cnt(mod);
	set<pair<int, int>> st;
	for (int i = 0; i < mod; i++) {
		st.insert({0, i});
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		x %= mod;
		st.erase({cnt[x], x});
		cnt[x]++;
		st.insert({cnt[x], x});
		auto it = st.begin();
		cout << it->F * 1ll * mod + it->S << '\n';
	}
}