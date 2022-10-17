#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, k; cin >> n >> k;
	ll tot = 0;
	ll sumPos = 0;
	rep(_,0,k) {
		ll pos, num;
		cin >> pos >> num;
		pos--;
		sumPos += pos*num;
		sumPos %= n;
		tot += num;
	}
	if (tot > n) {
		cout << -1 << endl;
	}
	else if (tot < n) {
		cout << 1 << endl;
	}
	else {
		ll expected = (n-1)*n/2;
		if (expected % n == sumPos) cout << 1 << endl;
		else cout << -1 << endl;
	}
}