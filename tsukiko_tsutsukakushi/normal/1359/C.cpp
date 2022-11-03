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

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

void solve() {
	int h, c, t; cin >> h >> c >> t;
    if(t == h) {
        cout << 1 << endl;
        return;
    }
    if(t == c) {
        cout << 2 << endl;
        return;
    }
    int x = t - c, y = h - t;
    int d = gcd(x, y);
    x /= d, y /= d;
    if(y == x) {
        cout << 2 << endl;
        return;
    }
    if(x > y) {
        //
        int sa = x - y;
        set<int> cand;
        cand.insert(y / sa);
        cand.insert((y + sa - 1) / sa);
        int ans = 2;
        ld res = abs((ld)(h + c) / 2.0 - (ld)t);
        for(auto a: cand) {
            ld temp = (ld)(c * a + h * (a + 1)) / (ld)(2 * a + 1);
            if(chmin(res, abs(temp - t))) {
                ans = 2 * a + 1;
            }
        }
        cout << ans << endl;
    } else {
        cout << 2 << endl;
        return;
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