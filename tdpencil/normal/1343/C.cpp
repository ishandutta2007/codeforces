#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector
#define lb lower_bound
#define ub upper_bound
#define pb push_back
int n, m,a, b;
void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}

void solve() {
	int n; cin >> n;
	vt<int> a(n);
	for(auto &i : a)
		cin >> i;
	
	vt<vt<int>> seg;
	vt<int> cur;
	int last = a[0];
	for(auto &i : a) {
		if(last > 0 == i > 0) {
			;
		} else {
			if(cur.size()) seg.push_back(cur);
			if(cur.size()) cur.clear();
		}
		cur.push_back(i);
		last = i;
	}
	if(cur.size()) seg.push_back(cur);
	ll s=0;
	for(auto i : seg) {
		ll x = *max_element(all(i));
		s += x;
	}
	cout << s << "\n";
}

int main() {
	io();
	int t = 1;
	cin >> t;
	while(t--) solve();
}