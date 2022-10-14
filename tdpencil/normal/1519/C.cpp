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

void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
int n, m, k;
const int mxN = 2e5 + 1;

pair<int, int> a[mxN];
vector<int> sol[mxN];
vector<ll> pref[mxN];
vector<ll> ans[mxN];
ll res[mxN];
void solve() 
{
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i].second;
	}

	for(int i = 0; i < n; i++) {
		sol[a[i].first].push_back(a[i].second);
	}
	for(int i = 1; i <= n; i++) {
		sort(sol[i].begin(), sol[i].end());
		reverse(all(sol[i]));
	}

	for(int i = 1; i <= n; i++) {
		if(sz(sol[i]) == 0) continue;
		pref[i].resize(sz(sol[i]));
		ans[i].resize(sz(sol[i]));
		pref[i][0] = sol[i][0];
		for(int j = 1; j < sz(sol[i]); j++) {
			pref[i][j] = pref[i][j - 1] + sol[i][j];
		}
		for(int j = 1; j <= sz(sol[i]); j++) {
			int up=sz(sol[i]) / j;
			up *= j;
			--up;
			assert(up < sz(sol[i]));
			ans[i][j - 1] = pref[i][up];
		}
	}
	// sum of ans[i][k]
	// do it quickly
	set<int> tosee;
	for(int i = 1; i <= n; i++) tosee.insert(i);
	for(int i = 1; i <= n; i++) {
		set<int> p;
		ll x = 0;
		for(int j : tosee) {
			if(sz(ans[j]) <= i - 1) {
				continue;
			} else {
				x += ans[j][i - 1];
				p.insert(j);
			}
		}
		tosee = p;
		res[i] = x;
	}
	
	for(int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	for(int i = 1; i <= n; i++) {
		if(sz(sol[i])) sol[i].clear();
		if(sz(pref[i])) pref[i].clear();
		if(sz(ans[i])) ans[i].clear();
		res[i] = 0;
	}
	cout << "\n";
} 

void prec() {

}
int main() {
	

	prec();
	io();
	
	int t = 1;
	cin >> t;
	while(t--) solve();
}