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
    vector<ll> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    sort(all(s));
    vector<ll> a(n - 1);
    rep(i, n - 1) {
        a[i] = s[i + 1] - s[i];
    }
    sort(all(a));
    reverse(all(a));
    vector<ll> suma(n, 0);
    rep(i, n - 1) {
        suma[i + 1] = suma[i] + a[i];
    }
    reverse(all(a));
    int q; cin >> q;
    rep(k, q) {
        ll l, r; cin >> l >> r;
        ll le = r - l + 1;
        int j = upper_bound(all(a), le) - a.begin();
        int co = n - 1 - j;
        ll ans = s[n - 1] + le - s[0];
        ans -= suma[co] - co * le;
        cout << ans << " \n"[k == q - 1];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}