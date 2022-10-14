#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector

int n, m;
void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
void solve() {
	set<int> s;
	int n; cin >> n;
	cin >> m;
	vector<int> a(n);
	for(auto &i : a)
		cin >> i;
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	vector<int> ans;
	for(auto &i : a) {
		if(s.count(i)) ans.push_back(i);
	}

	for(auto &i : ans)
		cout << i << " ";

}

int main() {
	io();
	int t = 1;
	//cin >> t;
	while(t--) solve();
}