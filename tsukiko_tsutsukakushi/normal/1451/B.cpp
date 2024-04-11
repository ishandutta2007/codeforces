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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    rep(_, q) {
        int l, r; cin >> l >> r;
        -- l;
        int cur = l;
        bool ok = 0;
        bool st = 0;
        int i = 0;
        for(; i < n;) {
            if(s[i] == s[cur]) {
                st = 1;
                ++ cur;
                if(!ok and cur == r - 1) ++ i, ok = 1;
            } else {
                if(st) ok = 1;
            }
            ++ i;
            if(cur == r) break;
        }
        if(cur == r and ok) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}