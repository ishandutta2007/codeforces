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
	ll u, v; cin >> u >> v;
    if(u == 0 && v == 0) {
        cout << 0 << endl;
        return;
    }
    if(u == v) {
        cout << 1 << endl << u << endl;
        return;
    }
    if(u > v) {
        cout << -1 << endl;
        return;
    }
    if(u % 2 != v % 2) {
        cout << -1 << endl;
        return;
    }
    bool ok = 1;
    ll p = 0, q = 0;
    ll u_ = u, v_ = v;
    for(int bit = 0; bit < 63; ++bit) {
        ll mask = (1LL<<bit);
        int x = (u >> bit) & 1;
        int y = (v >> bit) & 1;
        int nx = (u >> (bit + 1)) & 1;
        int ny = (v >> (bit + 1)) & 1;
        if(x == 1 && y == 1) {
            p += mask;
            if(nx != ny) {
                ok = 0;
            }
        } else if(x == 0 && y == 0) {
            if(nx != ny) {
                p += mask;
                q += mask;
                v -= 2 * mask;
            }
        } else if(x == 0 && y == 1) {
            if(nx != ny) {
                p += mask;
                q += mask;
                v -= 2 * mask;
            }
        } else if(x == 1 && y == 0) {
            p += mask;
            if(nx != ny) {
                ok = 0;
            }
        }
    }
    if(ok) {
        cout << 2 << endl << p << " " << q << endl;
        if((p ^ q) != u_ || p + q != v_) {
            cerr << "err" << u << " " << v << endl;  
        }
        return;
    }
    u = u_, v = v_;
    cout << 3 << endl;
    ll a = 0, b = 0, c = 0;
    for(int bit = 0; bit < 63; ++bit) {
        ll mask = (1LL<<bit);
        int x = (u >> bit) & 1;
        int y = (v >> bit) & 1;
        int nx = (u >> (bit + 1)) & 1;
        int ny = (v >> (bit + 1)) & 1;
        //cerr << x << " " << y << " " << nx << " " << ny << endl;
        if(nx != ny) {
            b += mask;
            c += mask;
            v -= 2 * mask;
        }
        if(x == 1 && y == 1) {
            a += mask;
        } else if(x == 0 && y == 0) {
            continue;
        } else if(x == 0 && y == 1) {
            continue;
        } else if(x == 1 && y == 0) {
            a += mask;
        }
    }
    cout << a << " " << b << " " << c << endl;
    if((a ^ b ^ c) != u_ || a + b + c != v_) {
            cerr << "err" << u << " " << v << endl;  
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}