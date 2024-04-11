/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool check(ll k, ll l, ll r, ll t, ll x, ll y) {
    if(k + y <= r) k += y;

    if(x == y) {
        if(k - x >= l) return true;
        else return false;
    } else if(x < y) {
        ll now = k;
        map<ll, bool> mp;
        mp[now] = 1;
        ll time = t;
        while(time > 0) {
            ll can = (now - l) / x;
            if(can == 0) return false;
            time -= can;
            now -= can * x;
            // if(mp[now]) break;
            // mp[now] = 1;
            ll can2 = (r - now) / y;
            // if(can2 == 0) return false;
            // time -= can2;
            chmin(can2, can);
            now += can2 * y;
            if(mp[now]) break;
            mp[now] = 1;
        }
        return true;
    } else {
        ld res = (ld)k - (ld)(x - y) * (ld)(t - 1) - (ld)x;
        if(res < -100.0) return false;
        ll rest = k - (x - y) * (t - 1) - x;
        if(rest >= l) return true;
        else return false;
    }
}

void solve() {
    ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
    cout << (check(k, l, r, t, x, y) ? "Yes" : "No") << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}