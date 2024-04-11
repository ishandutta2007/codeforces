/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < (n); ++ i)
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
    vector<string> d(3, "");
    vector<int> sz(3, 0);
    const int MAX = 255;
    vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(MAX, n + 1)));
    dp[0][0][0] = 0;
    vector<vector<int>> nxt(n + 3, vector<int>(26, n));
    per(i, n) {
        rep(j, 26) {
            nxt[i][j] = nxt[i + 1][j];
        }
        int ch = s[i] - 'a';
        nxt[i][ch] = i;
    }
    rep(i, q) {
        char op; int id;
        cin >> op >> id;
        -- id;
        if(op == '+') {
            char ch; cin >> ch;
            d[id].push_back(ch);
            // rep(j, 3) cerr << d[j] << " \n"[j == 2];
            sz[id] ++;
            if(id == 0) {
                rep(j, sz[1] + 1) {
                    rep(k, sz[2] + 1) {
                        if(sz[0] - 1 >= 0) chmin(dp[sz[0]][j][k], nxt[dp[sz[0] - 1][j][k]][d[0][sz[0] - 1] - 'a'] + 1);
                        if(j - 1 >= 0) chmin(dp[sz[0]][j][k], nxt[dp[sz[0]][j - 1][k]][d[1][j - 1] - 'a'] + 1);
                        if(k - 1 >= 0) chmin(dp[sz[0]][j][k], nxt[dp[sz[0]][j][k - 1]][d[2][k - 1] - 'a'] + 1);
                    }
                }
            } else if(id == 1) {
                rep(j, sz[0] + 1) {
                    rep(k, sz[2] + 1) {
                        if(sz[1] - 1 >= 0) chmin(dp[j][sz[1]][k], nxt[dp[j][sz[1] - 1][k]][d[1][sz[1] - 1] - 'a'] + 1);
                        if(j - 1 >= 0) chmin(dp[j][sz[1]][k], nxt[dp[j - 1][sz[1]][k]][d[0][j - 1] - 'a'] + 1);
                        if(k - 1 >= 0) chmin(dp[j][sz[1]][k], nxt[dp[j][sz[1]][k - 1]][d[2][k - 1] - 'a'] + 1);
                    }
                }
            } else {
                rep(j, sz[0] + 1) {
                    rep(k, sz[1] + 1) {
                        if(sz[2] - 1 >= 0) chmin(dp[j][k][sz[2]], nxt[dp[j][k][sz[2] - 1]][d[2][sz[2] - 1] - 'a'] + 1);
                        if(j - 1 >= 0) chmin(dp[j][k][sz[2]], nxt[dp[j - 1][k][sz[2]]][d[0][j - 1] - 'a'] + 1);
                        if(k - 1 >= 0) chmin(dp[j][k][sz[2]], nxt[dp[j][k - 1][sz[2]]][d[1][k - 1] - 'a'] + 1);
                    }
                }
            }
            // cerr << sz[0] << " " << sz[1] << " " << sz[2] << endl;
            cout << (dp[sz[0]][sz[1]][sz[2]] <= n ? "YES" : "NO") << "\n";
        } else if(op == '-') {
            sz[id] --;
            d[id].pop_back();
            if(id == 0) {
                rep(j, sz[1] + 1) {
                    rep(k, sz[2] + 1) {
                        dp[sz[0] + 1][j][k] = n + 1;
                    }
                }
            } else if(id == 1) {
                rep(j, sz[0] + 1) {
                    rep(k, sz[2] + 1) {
                        dp[j][sz[1] + 1][k] = n + 1;
                    }
                }
            } else {
                rep(j, sz[0] + 1) {
                    rep(k, sz[1] + 1) {
                        dp[j][k][sz[2] + 1] = n + 1;
                    }
                }
            }
            cout << (dp[sz[0]][sz[1]][sz[2]] <= n ? "YES" : "NO") << "\n";
        }
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