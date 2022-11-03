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
    vector<ll> a(n), b(n);
    map<ll, int> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    rep(i, n) {
        cin >> b[i];
    }
    vector<ll> m;
    for(auto p: mp) {
        if(p.sc >= 2) {
            m.push_back(p.fr);
        }
    }
    ll ans = 0;
    rep(i, n) {
        bool ok = 0;
        for(int mask: m) {
            if((mask & a[i]) == a[i]) {
                ok = 1;
            }
        }
        if(ok) ans += b[i];
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