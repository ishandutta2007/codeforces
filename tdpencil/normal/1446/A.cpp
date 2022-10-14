#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
// ll m, k, x, y;

// string s;
ll n, m, q, k;
const int mxN = 3e5+1;
const int M = 1e9+7;
bool vis[mxN];


void solve() {
	set<pair<int, int>> s;
	cin >> n >> k;
	vector<int> a(n);
	for(int &i :a)
		cin >> i;
	for(int i =0; i < n; i++)
		s.insert(make_pair(a[i], i));
	vector<int> id;

	sort(a.rbegin(), a.rend());
	ll cur = 0;
	ll t = (k/2) + (k&1);

	for(int i = 0; i < n; i++) {
		if(cur + a[i] <= k) {
			cur += a[i];
			id.push_back(a[i]);
		}
	}
	
	if(cur >= t && cur <= k) {
		cout << id.size() << "\n";
		for(int &i : id) {
			auto it = s.lower_bound(make_pair(i, 0));
			cout << (*it).second + 1 << " ";
			s.erase(it);
		}
		cout << "\n";
	} else {
		cout << -1 << "\n";
	}



}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}