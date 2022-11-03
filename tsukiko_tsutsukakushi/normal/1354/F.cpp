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

typedef pair<P, int> P2;

void solve() {
	int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<P2> c(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        c[i] = {{a[i], b[i]}, i};
    }
    sort(all(c), [&](P2 x, P2 y){ return x.fr.sc < y.fr.sc; });
    static int dp[80][80];
    rep(i, 80) {
        rep(j, 80) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    rep(i, n) {
        for(int j = 0; j <= i; ++ j) {
            if(dp[i][j] != -INF) chmax(dp[i + 1][j + 1], dp[i][j] + c[i].fr.fr + j * c[i].fr.sc);
            if(dp[i][j] != -INF) chmax(dp[i + 1][j], dp[i][j] + (k - 1) * c[i].fr.sc);
        }
    }
    int cur = dp[n][k];
    int p = n, q = k;
    vector<int> s(n, -1);
    for(int i = n - 1; i >= 0; -- i) {
        if(p - 1 >= 0 && q - 1 >= 0) {
            if(dp[p - 1][q - 1] + c[i].fr.fr + (q - 1) * c[i].fr.sc == cur) {
                s[i] = 0;
                p --; q --;
                cur = dp[p][q];
                continue;
            }
        }
        if(p - 1 >= 0) {
            if(dp[p - 1][q] + (k - 1) * c[i].fr.sc == cur) {
                s[i] = 1;
                -- p;
                cur = dp[p][q];
            }
        }
    }
    vector<int> ans, ba;
    int last = -1;
    rep(i, n) {
        if(s[i] == 0) {
            if((int)ans.size() < k - 1) ans.pb(c[i].sc + 1);
            else last = c[i].sc;
        } else {
            ba.pb(c[i].sc + 1);
        }
    }
    for(int x: ba) {
        ans.pb(x);
        ans.pb(-x);
    }
    ans.pb(last + 1);
    cout << (int)ans.size() << endl;
    rep(i, (int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}