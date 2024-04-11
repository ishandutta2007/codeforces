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
	int a, b, c, d; cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int xmi = x - max(0LL, a - b), xma = x + max(0LL, b - a), ymi = y - max(0LL, c - d), yma = y + max(0LL, d - c);
    bool xok = 1, yok = 1;
    if(x1 == x && x == x2) {
        if(a == 0 && b == 0) {
            xok = 1;
        } else {
            xok = 0;
        }
    } else {
        if(x1 <= xmi && xma <= x2) {
            xok = 1;
        } else {
            xok = 0;
        }
    }

    if(y1 == y && y == y2) {
        if(c == 0 && d == 0) {
            yok = 1;
        } else {
            yok = 0;
        }
    } else {
        if(y1 <= ymi && yma <= y2) {
            yok = 1;
        } else {
            yok = 0;
        }
    }

    if(xok && yok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}