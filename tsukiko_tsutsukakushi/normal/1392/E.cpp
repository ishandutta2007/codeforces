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

int n;

void solve() {
	cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    rep(i, n) {
        rep(j, n) {
            if(i == 0 and j == 0) continue;
            int k = i + j - 1;
            if(i % 2 == 0) a[i][j] = (1LL<<k);
        }
    }
    rep(i, n) {
        rep(j, n) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int q; cin >> q;
    rep(_, q) {
        int res; cin >> res;
        vector<P> ans(1, P{0, 0});
        int nowx = 0, nowy = 0;
        rep(j, 2 * n - 2) {
            if(res & (1LL<<j)) {
                if(nowx % 2 == 1) {
                    ++ nowx;
                } else {
                    ++ nowy;
                }
                ans.pb(P{nowx, nowy});
            } else {
                if(nowx % 2 == 0) {
                    ++ nowx;
                } else {
                    ++ nowy;
                }
                ans.pb(P{nowx, nowy});
            }
        }
        rep(j, ans.size()) {
            cout << ans[j].fr + 1 << " " << ans[j].sc + 1 << endl;
        }
    }
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}