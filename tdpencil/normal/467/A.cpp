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
// ll m, k, x, y;

// string s;
ll n, m, k;
void solve() {
	cin >> k;
	int ans = 0;
	while(k--) {
		cin >> n >> m;
		if(m-n>=2) {
			++ans;
		}
	}

	cout << ans << nl;
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int t = 1; //cin >> t;
	int t = 1;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}