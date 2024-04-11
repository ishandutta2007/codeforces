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
const ll INF=1LL<<62 ;
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

ll dist(LP a, LP b) {
    return abs(a.fr - b.fr) + abs(a.sc - b.sc);
}

void solve() {
	ll x0, y0, ax, ay, bx, by; 
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t; cin >> xs >> ys >> t;
    vector<LP> nodes(1, LP{x0, y0});
    ll x = x0, y = y0;
    while((INF - bx) / ax >= x && (INF - by) / ay >= y) {
        //cerr << x << " " << y << endl;
        x = ax * x + bx, y = ay * y + by;
        nodes.pb({x, y});
    }
    //int s = lower_bound(all(nodes), LP{xs, -INF}) - nodes.begin();
    ll ans = 0;
    rep(s, nodes.size()) {
        //first step up
    ll res;
    if(s < nodes.size() && dist({xs, ys}, nodes[s]) <= t) {
        res = dist({xs, ys}, nodes[s]);
        ll now = 1;
        chmax(ans, now);
        //second step up
        int j = s;
        while(res + dist(nodes[j], nodes[j + 1]) <= t) {
            now ++;
            res += dist(nodes[j], nodes[j + 1]);
            j ++;
            chmax(ans, now);
        }
        //cerr << now << endl;
        //second step down
        j = s;
        res = dist({xs, ys}, nodes[s]);
        now = 1;
        while(j - 1 >= 0 && res + dist(nodes[j], nodes[j - 1]) <= t) {
            now ++;
            res += dist(nodes[j], nodes[j - 1]);
            j --;
            chmax(ans, now);
        }
        //cerr << now << endl;
        j = 0;
        while(res + dist(nodes[j], nodes[j + 1]) <= t) {
            if(j + 1 >= s + 1) now ++;
            res += dist(nodes[j], nodes[j + 1]);
            j ++;
            chmax(ans, now);
        }
        //cerr << now << endl;
    }
    //first step down
    if(s - 1 >= 0 && dist({xs, ys}, nodes[s - 1]) <= t) {
        ll now = 1;
        res = dist({xs, ys}, nodes[s - 1]);
        //cerr << res << endl;
        chmax(ans, now);
        //second step up
        int j = s - 1;
        while(res + dist(nodes[j], nodes[j + 1]) <= t) {
            now ++;
            res += dist(nodes[j], nodes[j + 1]);
            j ++;
            chmax(ans, now);
        }
        //second step down
        j = s - 1;
        res = dist({xs, ys}, nodes[s - 1]);
        now = 1;
        while(j - 1 >= 0 && res + dist(nodes[j], nodes[j - 1]) <= t) {
            now ++;
            res += dist(nodes[j], nodes[j - 1]);
            j --;
            chmax(ans, now);
        }
        j = 0;
        while(res + dist(nodes[j], nodes[j + 1]) <= t) {
            if(j + 1 >= s) now ++;
            res += dist(nodes[j], nodes[j + 1]);
            j ++;
            chmax(ans, now);
        }
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