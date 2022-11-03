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
	int n, p, k; cin >> n >> p >> k;
    vector<int> a(n);
    vector<P> ps(n);
    rep(i, n) {
        cin >> a[i];
        ps[i] = make_pair(a[i], i);
    }
    sort(all(ps));
    reverse(all(ps));
    vector<vector<int>> s(n, vector<int>(p));
    rep(i, n) {
        rep(j, p) {
            cin >> s[i][j];
        }
    }
    static int dp[100100][(1<<7) + 10];
    rep(i, 100100) {
        rep(j, (1<<7) + 10) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    rep(i, n) {
        for(int bit = 0; bit < (1<<p); ++bit) {
            int cnt = __builtin_popcount(bit);
            int j = ps[i].sc;
            chmax(dp[i + 1][bit], dp[i][bit] + ( i + 1 - cnt <= k ? a[j] : 0));
            rep(k, p) {
                if(bit & (1<<k)) continue;
                chmax(dp[i + 1][bit | (1<<k)], dp[i][bit] + s[j][k]);
            }
        }
    }
    cout << dp[n][(1<<p) - 1] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}