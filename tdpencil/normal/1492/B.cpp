#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
// ll m, k, x, y;

// string s;
ll n, m, q;
const int mxN = 3e5+1;
const int M = 1e9+7;
// int a[mxN+1];
// ll b[mxN+1];
// ll dp[mxN+1];
bool vis[mxN];
const ll NF=-1e18;
// set<ll> s;


void solve() {
	cin >> n;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;

	set<int> s;
	for(int i = 1; i <= n; i++)
		s.insert(i);
	int p = n - 1;
	vector<int> ans;
	while(p >= 0) {
		int x = *(s.rbegin());
		vector<int> te;
		while(p >= 0 && a[p] != x) {
			te.push_back(a[p]);
			s.erase(a[p]);
			p--;
		}
		s.erase(a[p]);
		te.push_back(a[p]);
		reverse(te.begin(), te.end());
		for(int &i : te)
			ans.push_back(i);
		p--;
	}

	for(int &i : ans)
		cout << i << " ";
	cout << "\n";

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