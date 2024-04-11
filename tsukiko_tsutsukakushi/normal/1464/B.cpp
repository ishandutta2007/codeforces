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

void solve() {
	string s; cin >> s;
    ll x, y; cin >> x >> y;
    int n = (int)s.size();
    if(y > x) {
        rep(i, n) {
            if(s[i] == '?') continue;
            s[i] = (s[i] == '0' ? '1' : '0');
        }
        swap(x, y);
    }
    ll ans = INF;
    vector<int> left0(n + 1, 0), right0(n + 1, 0);
    rep(i, n) {
        left0[i + 1] = left0[i] + (s[i] != '1');
    }
    rep(i, n) {
        right0[i + 1] = right0[i] + (s[n - 1 - i] != '1');
    }
    int res = 0;
    rep(i, n) {
        // cerr << i - left0[i] << "\n";
        if(s[i] == '0') {
            res += y * (i - left0[i]);
        } else if(s[i] == '1') {
            res += x * left0[i];
        } else {
            // ? -> 0
            res += y * (i - left0[i]);
        }
    }
    chmin(ans, res);
    // cerr << res << "\n";
    int offset = 0;
    rep(i, n) {
        if(s[i] == '?') {
            // 0 -> 1
            // cerr << right0[n - i] << "\n";
            res -= y * (i - left0[i] + offset) + x * (n - 1 - i - right0[n - 1 - i]);
            res += x * (left0[i] - offset) + y * (right0[n - 1 - i]);
            ++ offset;
            // cerr << res << "\n";
            chmin(ans, res);
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}