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
    vector<pair<int, int>> l, d;
	int n; cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	cin >> s;
	ans=0;
	vi id(n);
	rep(i,0,n) {
		if(s[i] == '1') l.push_back({a[i], i});
		if(s[i] == '0') d.push_back({a[i], i});
	}
	sort(l.begin(), l.end());
    sort(d.begin(), d.end());
    int f = 1;
    for(auto &e : d) {
        e.first = f++;
    }
    for(auto &e : l) {
        e.first = f++;
    }
    for(auto e : l) a[e.second] = e.first;
    for(auto e : d) a[e.second] = e.first;
    
    rep(i,0,n) cout << a[i] << " ";
    cout << "\n";
    // we know l must have 1..l.size()
	
}
int main() {
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}