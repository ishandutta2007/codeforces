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
	int n, c; cin >> n >> c;
    vector<int> a(n - 1), suma(n, 0);
    rep(i, n - 1) {
        cin >> a[i];
        suma[i + 1] = suma[i] + a[i];
    }
    vector<int> b(n - 1), sumb(n, 0);
    rep(i, n - 1) {
        cin >> b[i];
        sumb[i + 1] = sumb[i] + b[i];
    }
    static int dp[200200][2];
    rep(i, 200200) {
        dp[i][0] = dp[i][1] = INF;
    }
    dp[0][0] = 0;
    rep(i, n - 1) {
        chmin(dp[i + 1][0], dp[i][0] + a[i]);
        chmin(dp[i + 1][0], dp[i][1] + a[i]);
        chmin(dp[i + 1][1], dp[i][1] + b[i]);
        chmin(dp[i + 1][1], dp[i][0] + c + b[i]);
    }
    rep(i, n) {
        if(i) cout << " ";
        cout << min(dp[i][0], dp[i][1]);
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