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
 	vi nums;
	int n; cin >> n;
	for(int i=2;i*i<=n;i++) {
		while(n%i==0) {
			nums.push_back(i);
			n /= i;
		}
	}
	if(n>1) nums.push_back(n);
	int x=1;
	vi ans;
	set<int> seen;
	while(sz(nums)) {
		x*=nums.back();
		if(!seen.count(x)) ans.push_back(x),seen.insert(x),x=1;
		nums.pop_back();
	}
	//rep(i,0,sz(ans)) cout << ans[i] << " ";
	//cout << "\n";
	if(sz(ans)>=3) {
		cout << "YES\n";
		rep(i,0,2) cout << ans[i] << " ";
		rep(i,2,sz(ans)) x*=ans[i];
		cout << x;
		cout << "\n";
	} else {
		cout << "NO\n";
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}