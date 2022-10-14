#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


string s;
ll ans, i, j;

void solve() {
    int n; cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int num = -1;
	if(count(all(a), a[0]) == n) {
	    cout << 0 << "\n";
	    return;
	}
	rep(i,1,301) {
		if(num != -1) break;
		map<int, int> s;
		rep(j,0,n) s[a[j]-i]++,s[a[j]]++, s[a[j]+i]++;
		for(auto e : s) {
			if(e.second >= n) num = i;
		}
	}
	cout << num << "\n";
}
int32_t main() {
    int t = 1;
	// cin >> t;
    while(t--) {
        solve();
    }
}