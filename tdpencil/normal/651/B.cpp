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
int n, m;
void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
int a[2000], cnt[2001];
void solve() {
	vt<int> vs;
	cin >> n; for(int i =0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) ++cnt[a[i]];
	for(int i = 0; i < 2000; i++) {
		for(int j = 0; j < 2000; j++) {
			if(cnt[j] > 0) {
				vs.push_back(j);
			}
			--cnt[j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n - 1; i++) {
		if(vs[i] < vs[i + 1]) ++ans;
	}

	cout << ans << "\n";
} 

int main() {
	io();
	int t = 1;
	// cin >> t;
	while(t--) solve();
}