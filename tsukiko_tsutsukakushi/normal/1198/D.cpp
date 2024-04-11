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

int dp[55][55][55][55];

void solve() {
    int n; cin >> n;
    vector<vector<char>> f(n, vector<char>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> f[i][j];
        }
    }
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    rep(i, n) {
        rep(j, n) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (f[i][j] == '#');
        }
    }
    auto cnt = [&](int i, int j, int x, int y) -> int {
        return sum[x][y] - sum[i][y] - sum[x][j] + sum[i][j];
    };
    rep(i, 55) {
        rep(j, 55) {
            rep(x, 55) {
                rep(y, 55) {
                    dp[i][j][x][y] = inf;
                }
            }
        }
    }
    auto rec = [&](auto &&self, int i, int j, int x, int y) -> int {
        if(i >= x or j >= y) return 0;
        if(dp[i][j][x][y] != inf) return dp[i][j][x][y];
        if(cnt(i, j, x, y) == 0) return 0;
        int res = max(x - i, y - j);
        for(int k = i + 1; k < x; ++ k) {
            chmin(res, self(self, i, j, k, y) + self(self, k, j, x, y));
        }
        for(int k = j + 1; k < y; ++ k) {
            chmin(res, self(self, i, j, x, k) + self(self, i, k, x, y));
        }
        return dp[i][j][x][y] = res;
    };
    cout << rec(rec, 0, 0, n, n) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}