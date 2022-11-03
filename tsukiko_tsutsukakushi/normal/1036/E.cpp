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
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct P {
    int x, y;
};

ld ex(P s, P t, P r) {
    ld x1 = (ld)t.x - (ld)s.x;
	ld y1 = (ld)t.y - (ld)s.y;
	ld x2 = (ld)r.x - (ld)s.x;
	ld y2 = (ld)r.y - (ld)s.y;
	return x1 * y2 - x2 * y1;
}

bool cross(P a, P b, P s, P t) {
	if (ex(a, b, s) * ex(a, b, t) > 0)
		return false;
    if (ex(b, a, s) * ex(b, a, t) > 0)
		return false;
	if (ex(t, s, a) * ex(t, s, b) > 0)
		return false;
	return ex(s, t, a) * ex(s, t, b) < eps;
}

pair<bool, pair<ld, ld>> intersection_ls(P a1, P a2, P b1, P b2) {
	ld d1 = abs(ex(b1, a1, b2));
	ld d2 = abs(ex(b1, a2, b2));
    if(!cross(a1, a2, b1, b2)) {
        return {false, {0.0, 0.0}};
    }
	return { true, {a1.x + (a2.x - a1.x) * d1 / (d1 + d2), a1.y + (a2.y - a1.y) * d1 / (d1 + d2)}};
}

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

void solve() {
	int n; cin >> n;
    vector<pair<P, P>> vec;
    int ans = 0;
    rep(i, n) {
        int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
        vec.pb({ P{ax, ay}, P{bx, by}});
        ans += gcd(abs(ax - bx), abs(ay - by)) + 1;
    }
    //cerr << ans << endl;
    map<pair<int, int>, int> mp;
    rep(i, n) {
        for(int j = i + 1; j < n; ++j) {
            auto res = intersection_ls(vec[i].fr, vec[i].sc, vec[j].fr, vec[j].sc);
            if(!res.fr) continue;
            ld X = res.sc.fr, Y = res.sc.sc;
            if(floor(X + eps) < X + 2 * eps && floor(X + eps) > X - 2 * eps) {
                if(floor(Y + eps) < Y + 2 * eps && floor(Y + eps) > Y - 2 * eps) {
                    mp[{floor(X + eps) , floor(Y + eps) }] ++;
                    //cerr << floor(X + eps) << " " floor(Y + eps) <<
                }
            }
        }
    }
    for(auto p: mp) {
        int k = 2;
        while(k * (k - 1) / 2 <= p.sc) {
            if(k * (k - 1) / 2 == p.sc) {
                ans -= (k - 1);
                break;
            }
            ++k;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}