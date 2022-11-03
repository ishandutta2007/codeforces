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

int pw(int x, int a) {
    if(a == 0) return 1;
    return x * pw(x, a - 1);
} 

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    static int dp[5050][4];
    rep(i, 5050) {
        rep(j, 4) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 4) {
            for(int k = j; k < 4; ++ k) {
                chmax(dp[i + 1][k], dp[i][j] + a[i] * pw(-1, k));
            }
        }
    }
    vector<int> st(n + 1, 3);
    int now = max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
    per(i, n) {
        int x = 0;
        for(int j = 3; j >= 0; -- j) {
            for(int k = 3; k >= 0; -- k) {
                if(now == dp[i + 1][k] && dp[i + 1][k] == dp[i][j] + a[i] * pw(-1, k)) {
                    st[i] = k;
                    x = j;
                    //cerr << "j = " << j << endl;
                }
            }
        }
        // cerr << st[i] << " ";
        // cerr << now << endl;
        now = dp[i][x];
    }
    int f = 0;
    rep(i, n + 1) {
        while(st[i] > f) {
            cout << i << " ";
            ++ f;
        }
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