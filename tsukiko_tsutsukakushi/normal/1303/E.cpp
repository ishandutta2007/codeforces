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

vector<vector<int>> calcnext(string s) {
    int n = (int)s.size();
    vector<vector<int>> res(n + 1, vector<int>(26, n));
    for(int i = n - 1; i >= 0; --i) {
        rep(j, 26) {
            res[i][j] = res[i + 1][j];
        }
        res[i][s[i] - 'a'] = i;
    }
    return res;
}

void solve() {
	string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    vector<vector<int>> next = calcnext(s);
    for(int i = 0; i < m; ++i) {
        string tb = t.substr(0, i), tf = t.substr(i);
        vector<vector<int>> dp(n + 3, vector<int>(n + 3, INF));
        dp[0][0] = 0;
        rep(j, (int)tb.size() + 1) {
            rep(k, (int)tf.size() + 1) {
                int bdp = dp[j][k];
                if(bdp >= n) continue;
                //cerr << bdp << endl;
                if(j < (int)tb.size() && next[bdp][tb[j] - 'a'] != n) {
                    chmin(dp[j + 1][k], next[bdp][tb[j] - 'a'] + 1);
                }
                if(k < (int)tf.size() && next[bdp][tf[k] - 'a'] != n) {
                    chmin(dp[j][k + 1], next[bdp][tf[k] - 'a'] + 1);
                }
            }
        }
        //cerr << dp[(int)tb.size()][(int)tf.size()] << endl;
        if(dp[(int)tb.size()][(int)tf.size()] <= n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}