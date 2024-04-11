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
#define lower_b(a,b) lower_bound(all(a),b)-a.begin()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
    vector<int> x(6), y(6);
    vector<int> X, Y;
    X.pb(0), X.pb(inf);
    Y.pb(0), Y.pb(inf);
	rep(i, 6) {
        cin >> x[i] >> y[i];
        X.pb(x[i]);
        Y.pb(y[i]);
    }
    auto xcom = compress(X);
    auto ycom = compress(Y);
    int xsz = (int)xcom.size(), ysz = (int)ycom.size();
    vector<vector<int>> f(xsz, vector<int>(ysz, -1));
    for(int i = lower_b(xcom, x[0]); i < lower_b(xcom, x[1]); ++ i) {
        for(int j = lower_b(ycom, y[0]); j < lower_b(ycom, y[1]); ++ j) {
            f[i][j] = 0;
        }
    }
    for(int i = lower_b(xcom, x[2]); i < lower_b(xcom, x[3]); ++ i) {
        for(int j = lower_b(ycom, y[2]); j < lower_b(ycom, y[3]); ++ j) {
            f[i][j] = 1;
        }
    }
    for(int i = lower_b(xcom, x[4]); i < lower_b(xcom, x[5]); ++ i) {
        for(int j = lower_b(ycom, y[4]); j < lower_b(ycom, y[5]); ++ j) {
            f[i][j] = 1;
        }
    }
    rep(i, xsz) {
        rep(j, ysz) {
            if(f[i][j] == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}