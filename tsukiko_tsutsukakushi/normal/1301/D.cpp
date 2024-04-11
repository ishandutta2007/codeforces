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
	int n, m, k; cin >> n >> m >> k;
    // if(k > 4 * n * m - 2 * n - 2 * m) {
    //     cout << "NO" << endl;
    //     return;
    // }
    //corner case
    if(n == 1) {
        if(k < m - 1) {
            cout << "YES" << endl << 1 << endl << k << " " << "R" << endl;
            return;
        } else if(k <= 2 * m - 2) {
            cout << "YES" << endl << 2 << endl << m - 1 << " " << "R" << endl << k - m + 1 << " L" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(m == 1) {
        if(k < n - 1) {
            cout << "YES" << endl << 1 << endl << k << " " << "D" << endl;
            return;
        } else if(k <= 2 * n - 2) {
            cout << "YES" << endl << 2 << endl << n - 1 << " " << "D" << endl << k - n + 1 << " U" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(k < n - 1) {
        cout << "YES" << endl << 1 << endl << k << " " << "D" << endl;
        return;
    }
    k -= (n - 1);
    vector<int> f(1, n - 1); vector<string>s(1, "D");
    int ncnt = 0, mcnt = 0;
    while(k > 0) {
        if(n > 1 && ncnt < m - 1) {
            if(k >= 2 * n - 1) {
                f.pb(1); f.pb(n - 1); f.pb(n - 1);
                s.pb("R"); s.pb("U"); s.pb("D");
                k -= (2 * n - 1);
            } else if(k > n) {
                f.pb(1); f.pb(n - 1); f.pb(k - n);
                s.pb("R"); s.pb("U"); s.pb("D");
                k = 0;
            } else if(k > 1) {
                f.pb(1); f.pb(k - 1);
                s.pb("R"); s.pb("U");
                k = 0;
            } else {
                f.pb(k);
                s.pb("R");
                k = 0;
            }
            ncnt ++;
        } else if(m > 1 && mcnt < n - 1) {
            if(k >= 2 * m - 1) {
                f.pb(m - 1); f.pb(1); f.pb(m - 1);
                s.pb("L"); s.pb("U"); s.pb("R");
                k -= (2 * m - 1);
            } else if(k > m) {
                f.pb(m - 1); f.pb(1); f.pb(k - m);
                s.pb("L"); s.pb("U"); s.pb("R");
                k = 0;
            } else if(k > m - 1) {
                // k = m
                f.pb(m - 1); f.pb(1);
                s.pb("L"); s.pb("U");
                k = 0;
            } else {
                f.pb(k);
                s.pb("L");
                k = 0;
            }
            mcnt ++;
        } else {
            if(m == 1 || k > m - 1) {
                cout << "NO" << endl;
                return;
            }
            f.pb(k);
            s.pb("L");
            k = 0;
        }
    }
    cout << "YES" << endl;
    cout << (int)f.size() << endl;
    rep(i, (int)f.size()) {
        cout << f[i] << " " << s[i] << endl;
    }
    //cerr << f.size() << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}