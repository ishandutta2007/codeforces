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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
using namespace std;

#define int long long
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
	int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k, -inf));
    dp[0][0] = 0;
    rep(i, n) {
        vector<vector<int>> sdp(m + 2, vector<int>(k, -inf));
        sdp[0][0] = 0;
        rep(j, m) {
            for(int p = m; p >= 0; -- p) {
                rep(q, k) {
                    chmax(sdp[p + 1][(q + a[i][j]) % k], sdp[p][q] + a[i][j]);
                }
            }
        }
        vector<int> sdp2(k, -inf);
        sdp2[0] = 0;
        rep(j, k) {
            for(int p = 0; p <= m / 2; ++ p) {
                chmax(sdp2[j], sdp[p][j]);
            }
        }
        rep(j, k) {
            rep(p, k) {
                chmax(dp[i + 1][(j + p) % k], dp[i][j] + sdp2[p]);
            }
        }
    }
    cout << dp[n][0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}