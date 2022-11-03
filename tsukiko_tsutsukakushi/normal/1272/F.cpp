/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    static int dp[202][202][202];
    static vector<int> prv[202][202][202];
    rep(i, 202) {
        rep(j, 202) {
            rep(k, 202) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    rep(i, n + 1) {
        rep(j, m + 1) {
            rep(k, 201) {
                int i2 = i + (s[i] == '(');
                int j2 = j + (t[j] == '(');
                int k2 = k + 1;
                if(chmin(dp[i2][j2][k2], dp[i][j][k] + 1)) {
                    prv[i2][j2][k2] = {i, j, k};
                }
            }
            per1(k, 200) {
                int i2 = i + (s[i] == ')');
                int j2 = j + (t[j] == ')');
                int k2 = k - 1;
                if(chmin(dp[i2][j2][k2], dp[i][j][k] + 1)) {
                    prv[i2][j2][k2] = {i, j, k};
                }
            }
        }
    }
    string ans = "";
    int i = n, j = m, k = 0;
    while(i > 0 || j > 0 || k != 0) {
        auto& v = prv[i][j][k];
        ans += (k - v[2] == -1 ? ')' : '(');
        i = v[0], j = v[1], k = v[2];
        // bool ok = 0;
        // rep(x, 2) {
        //     rep(y, 2) {
        //         for(int z = -1; z <= 1; z += 2) {
        //             if(ok) break;
        //             int ni = i - x, nj = j - y, nk = k + z;
        //             cerr << dp[i][j][k] << " " << dp[ni][nj][nk] << endl;
        //             if(ni >= 0 && nj >= 0 && nk >= 0 && dp[i][j][k] == dp[ni][nj][nk] + 1) {
        //                 if(z == -1) {
        //                     ans += '(';
        //                 } else {
        //                     ans += ')';
        //                 }
        //                 i = ni, j = nj, k = nk, ok = 1;
        //             }
        //             cerr << i << " " << j << " " << k << endl;
        //         }
        //     }
        // }
        // if(!ok) break;
    }
    reverse(all(ans));
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