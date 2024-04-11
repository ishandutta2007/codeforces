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
ll a[mxN+1];
ll b[mxN+1];
ll dp[mxN+1];
bool vis[mxN];
const ll NF=-1e18;
// set<ll> s;

// height that is smaller
/*
for every negative
we need to check for two things
one if there is a smaller building with a bigger beauty
or if there is a building larger than this
that is more negative correct?
*/

/*
for every negative
we need to check for two things
one if there is a smaller building with a bigger beauty
or if there is a building larger than this
that is more negative correct?
*/
void solve() {
	cin >> n;
	set<int> s, t;
	// cout << "OK";
	for(int i = 0; i < n; i++) s.insert(i+1);


	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans;

	ans.push_back(a[0]);

	s.erase(a[0]);

	// cout << "OK\n";

	vector<int> ans2;
	for(int i = 1; i < n; i++) {
		if(a[i] == a[i-1]) {
			ans.push_back(*s.begin());
			s.erase(*s.begin());
		} else {
			ans.push_back(a[i]);
			s.erase(a[i]);
		}
	}

	// cout << "OK\n";

	for(int i = 0; i < n; i++) t.insert(a[i]);
	s.clear();
	for(int i = 1; i <= n; i++) {
		s.insert(i);
	}
	
	// cout << "OK\n";
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(-100);
	for(auto &e: t)
		pq.push(e);

	pq.push(3400000);
	// min q

	for(int i = 0; i < n; i++) {
		if(pq.top() != a[i]) {
			ans2.push_back(a[i]);
			pq.pop();
			s.erase(a[i]);
		} else {
			int p = pq.top();
			auto it = s.lower_bound(p);
			if(it == s.begin()) {
				cout << *it << "\n";
				break;
			}
			it--;
			// cout << "NEW IT" << *it << "\n";
			ans2.push_back(*it);
			s.erase(it);
		}
	}

	for(auto &e: ans) {
		cout << e << " ";
	}
	cout << "\n";
	for(auto &e: ans2) {
		cout << e << " ";
	}
	cout << "\n";
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}