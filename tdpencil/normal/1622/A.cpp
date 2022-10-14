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
    vi a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(all(a));
	if(a[1] == a[2]) {
		if(a[0] % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}
	if(a[0] == a[1]) {
		if(a[2] % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}
	if(a[2] == a[0] + a[1]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
int main() {
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}