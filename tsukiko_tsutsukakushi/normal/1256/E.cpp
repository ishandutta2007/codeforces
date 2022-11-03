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

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    vector<P> b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all(b));
    int res = b[n - 1].fr - b[0].fr;
    static int dp[200200][3];
    rep(i, 200200) {
        rep(j, 3) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i < n; ++ i) {
        chmax(dp[i][1], dp[i - 1][0]);
        chmax(dp[i][2], dp[i - 1][1]);
        chmax(dp[i][2], dp[i - 1][2]);
        chmax(dp[i][0], dp[i - 1][2] + abs(b[i].fr - b[i - 1].fr));
    }
    cout << res - dp[n - 1][2] << " ";
    vector<int> ans(n, 0);
    int cur = 1;
    int j = 2;
    ans[b[n - 1].sc] = 1;
    for(int i = n - 2; i >= 0; -- i) {
        if(j - 1 >= 0 && dp[i][j - 1] == dp[i + 1][j]) {
            j --;
            ans[b[i].sc] = cur;
        } else if(j == 2 && dp[i][2] == dp[i + 1][2]) {
            j = 2;
            ans[b[i].sc] = cur;
        } else if(j == 0) {
            ans[b[i].sc] = cur + 1;
            ++ cur;
            j = 2;
        }
    }
    cout << cur << endl;
    rep(i, n) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}