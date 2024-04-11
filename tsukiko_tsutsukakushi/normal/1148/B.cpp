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
    int n, m, k; ll ta, tb; cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n), b(m);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        cin >> b[i];
    }
    if(n <= k or m <= k) {
        cout << -1 << endl;
        return;
    }
    ll ans = -1;
    for(int i = 0; i <= k; ++ i) {
        int j = lower_bound(all(b), a[i] + ta) - b.begin();
        int l = j + (k - i);
        if(l >= m) {
            cout << -1 << endl;
            return;
        }
        chmax(ans, b[l] + tb);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}