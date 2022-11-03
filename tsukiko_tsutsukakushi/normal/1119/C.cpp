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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            cin >> b[i][j];
        }
    }
    vector<vector<int>> c(n, vector<int>(m, 0));
    rep(i, n) {
        rep(j, m) {
            if(a[i][j] != b[i][j]) {
                c[i][j] = 1;
            }
            // cerr << c[i][j] << " \n"[j == m - 1];
        }
    }
    rep(i, n) {
        int co = 0;
        rep(j, m) if(c[i][j]) ++ co;
        if(co & 1) {
            cout << "No" << endl;
            return;
        }
    }
    rep(j, m) {
        int co = 0;
        rep(i, n) if(c[i][j]) ++ co;
        if(co & 1) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}