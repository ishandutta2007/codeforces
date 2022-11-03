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

int n, m;
vector<vector<char>> a;

void solve() {
	cin >> n >> m;
    a.assign(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    if(n >= 4) {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> dp(m, vector<int>((1<<n), inf));
    vector<vector<int>> to((1<<n));
    rep(bit, (1<<n)) {
        rep(bit2, (1<<n)) {
            bool check = 1;
            rep(j, n - 1) {
                int c = 0;
                c += (1 & (bit>>(j + 1)));
                c += (1 & (bit>>j));
                c += (1 & (bit2>>(j + 1)));
                c += (1 & (bit2>>j));
                if(c % 2 == 0) check = 0;
            }
            if(check) to[bit].pb(bit2);
        }
    }
    rep(i, (1<<n)) {
        int co = 0;
        rep(j, n) {
            if(i & (1<<j)) {if(a[j][0] == '0') ++ co;}
            else {if(a[j][0] == '1') ++ co;}
        }
        dp[0][i] = co;
    }
    for(int i = 1; i < m; ++ i) {
        rep(bit, (1<<n)) {
            for(int bit2: to[bit]) {
                int co = 0;
                rep(j, n) {
                    if(bit2 & (1<<j)) {if(a[j][i] == '0') ++ co;}
                    else if(!(bit2 & (1<<j))) {if(a[j][i] == '1') ++ co;}
                }
                chmin(dp[i][bit2], dp[i - 1][bit] + co);
            }
        }
    }
    int ret = inf;
    rep(i, (1<<n)) {
        chmin(ret, dp[m - 1][i]);
    }
    if(ret == inf) cout << -1 << endl;
    else cout << ret << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}