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

const int dx[2] = {-1, 0};
const int dy[2] = {0, -1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            if((i + j) % 2 == 0 and a[i][j] % 2 == 1) ++ a[i][j];
            if((i + j) % 2 == 1 and a[i][j] % 2 == 0) ++ a[i][j];
            cout << a[i][j] << " \n"[j == m - 1]; 
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}