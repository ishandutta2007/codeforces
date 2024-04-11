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
	array<int, 3> a, b;
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	int x = (a[0] + a[1] + a[2] + 4) / 5;
	int y = (b[0] + b[1] + b[2] + 9) / 10;
	int n; cin >> n;
	
	cout << (n >= x + y ? "YES" : "NO");
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
//	cin >> t;
    while(t--) {
        solve();
    }
}