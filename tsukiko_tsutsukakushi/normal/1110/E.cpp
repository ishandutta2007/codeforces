/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int n; cin >> n;
    vector<int> c(n), t(n);
    rep(i, n) {
        cin >> c[i];
    }
    rep(i, n) {
        cin >> t[i];
    }
    if(c[0] != t[0] or c[n - 1] != t[n - 1]) {
        cout << "No" << endl;
        return;
    }
    vector<int> a, b;
    rep(i, n - 1) {
        a.push_back(c[i + 1] - c[i]);
        b.push_back(t[i + 1] - t[i]);
    }
    sort(all(a)), sort(all(b));
    cout << (a == b ? "Yes" : "No") << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}