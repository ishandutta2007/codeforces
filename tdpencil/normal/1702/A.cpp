#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t=1;

const int mxN=2e5;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> t;
	while(t--) {
		int a;
		cin >> a;
		ll x = 1;
		int ans=2e9;
		while(x<=a) {
			ans=min((int)abs(x-a),ans);
			x*=10;
		}
		cout << ans << "\n";
	}
}