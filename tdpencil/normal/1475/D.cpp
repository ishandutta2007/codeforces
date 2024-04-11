#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
#define nl "\n"
#define en "\n"
#define eb emplace_back
#define trav(i, j) for(auto &i : j)
#define FOR(i, P) for(int i = 0; i < int(P); i++)
#define all(x) x.begin(),x.end()
#define x first
#define y second
ll n, m, k;



void solve() {
    cin >> n >> m;
    vector<pair<int, int>> a(n);
	ll res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].x;
		res+=a[i].x;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].y;
    }
	if(res < m) {
		cout << -1 << nl;
		return;
	}
	vector<ll> pq1, pq2;
	// min q?
	for(int i = 0; i < n; i++) {
		if(a[i].y == 1) pq1.pb(a[i].x);
		else pq2.pb(a[i].x);
	}
	sort(pq1.rbegin(), pq1.rend());
	sort(pq2.rbegin(), pq2.rend());
	partial_sum(all(pq1), pq1.begin());
	partial_sum(all(pq2), pq2.begin());
	int ans = 10000000;
	
	for(int i = 0; i < pq1.size(); i++) {
		ll res = pq1[i];
		int p = lower_bound(pq2.begin(), pq2.end(), m - res) - pq2.begin();
		if(p == pq2.size()) continue;
		if(m-res <= 0) p=-1;
		
		ans = min(1*(i+1) + 2*(p+1), ans);
	}
	int p1 = lower_bound(pq2.begin(), pq2.end(), m) - pq2.begin();
	if(p1 != pq2.size()) {
		ans = min(ans, 2 * (p1+1));
	}
	int p2 = lower_bound(pq1.begin(), pq1.end(), m) - pq1.begin();
	if(p2 != pq1.size()) {
		ans = min(ans, (p2+1));
	}
	
	cout << ans << "\n";
	


}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	// int t = 1;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}