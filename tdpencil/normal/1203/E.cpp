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
int n, m;
const int mxN = 2e5 + 1;
int a[mxN], cnt[mxN];
void solve() {
	set<int> seen;
	cin >> n;
	vt<int> a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	
	reverse(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		
			if(!seen.count(a[i] + 1)) {
				seen.insert(a[i] + 1);
			} else if(!seen.count(a[i])) {
				seen.insert(a[i]);
			} else {
				if(a[i] - 1 != 0) seen.insert(a[i] - 1);
			}
	}

	cout << sz(seen) << "\n";
} 

int main() {
	io();
	int t = 1;
	// cin >> t;
	while(t--) solve();
}