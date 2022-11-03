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
    int n, m; cin >> n >> m;
    vector<vector<char>> f(n, vector<char>(m));
    vector<vector<int>> cnt(n, vector<int>(m + 1, 0));
    rep(i, n) {
        rep(j, m) {
            cin >> f[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            cnt[i][j + 1] = cnt[i][j] + (f[i][j] == '*');
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            if(f[i][j] == '.') continue;
            for(int k = 1; k <= m; ++ k) {
                if(j + k - 1 < m and j - k + 1 >= 0 and i + k - 1 < n and cnt[i + k - 1][j + k] - cnt[i + k - 1][j - k + 1] == 2 * k - 1) {
                    ++ ans;
                } else break;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}