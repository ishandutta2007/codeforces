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

int a[1000100], b[1000100], ans[1000100];
int tim[1000100];
bool ok[1000100];

void solve() {
	int r, n; cin >> r >> n;
    vector<int> t(n), x(n), y(n);
    a[0] = 1, b[0] = 1;
    ok[0] = 1;
    rep(i, n) {
        cin >> t[i] >> x[i] >> y[i];
        // -- x[i], -- y[i];
        a[t[i]] = x[i], b[t[i]] = y[i];
    }
    vector<int> dp(n, 0);
    rep(i, n) {
        for(int j = t[i] - 1; j >= max(0LL, t[i] - 1010); -- j) {
            if(a[j] == 0 or b[j] == 0) {
                continue;
            }
            if(abs(x[i] - a[j]) + abs(y[i] - b[j]) <= t[i] - j) {
                if(ok[j] and chmax(dp[i], ans[j] + 1)) {
                    // cerr << t[i] << endl;
                    // cerr << a[j] << " " << b[j] << endl;
                    // cerr << abs(x[i] - a[j]) + abs(y[i] - b[j]) << " " << t[i] - j << endl;
                    // cerr << i << " " << j << " " << ans[j] << endl;
                    ans[t[i]] = dp[i];
                    ok[t[i]] = 1;
                }
            }
        }
        for(int j = (i == 0 ? 0 : t[i - 1] - 1) ; j <= t[i]; ++ j) {
            tim[j + 1] = max(tim[j], ans[j]);
        }
        if(t[i] >= 1010) {
            int mi = t[i] - 1010;
            if(chmax(dp[i], tim[mi + 1] + 1)) {
                ans[t[i]] = dp[i];
                ok[t[i]] = 1;
            }
        }
        // int mi = max(0LL, t[i] - 1010);
        // // cerr << mi << " " << tm[mi + 1] << endl;
        // if(chmax(dp[i], tm[mi + 1] + 1)) {
        //     ans[t[i]] = dp[i];
        //     ok[t[i]] = 1;
        // }
        // cerr << dp[i] << endl;
    }
    cout << *max_element(all(dp)) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}