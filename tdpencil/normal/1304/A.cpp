#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



void solve() {
    int x, y, a, b;
	cin >> x >> y >> a >> b;
	
	if((y-x) % (a + b) == 0) {
		cout << (y-x) / (a+b) << "\n";
	} else {
		cout << -1 << "\n";
	}
}
int32_t main() {
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}