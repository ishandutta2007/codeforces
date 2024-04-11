#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], q, b[mxN];
ll rg;
map<ar<int, 2>, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		rg+=a[i];
	}
	cin >> q;
	for(int s, t, u; q--; ) {
		cin >> s >> t >> u, --s, --u;
		auto it=mp.find({s, t});
		if(it!=mp.end()) {
			if(b[it->second]>a[it->second])
				--rg;
			--b[it->second];
			mp.erase(it);
		}
		if(~u) {
			mp[{s, t}]=u;
			++b[u];
			if(b[u]>a[u])
				++rg;
		}
		cout << rg-mp.size() << "\n";
	}
}