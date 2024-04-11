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
	int n, T; cin >> n >> T;
    vector<int> a(n), t(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> t[i];
    }
    vector<P> h, l;
    ld tmp = 0.0, ans = 0.0;
    rep(i, n) {
        if(t[i] > T) {
            h.pb({t[i], a[i]});
        } else if(t[i] < T) {
            l.pb({t[i], a[i]});
        } else {
            tmp += a[i];
        }
    }
    sort(all(h));
    sort(all(l));
    reverse(all(l));
    //
    ld res = 0.0; int now = 0;
    rep(i, l.size()) {
        res += l[i].sc;
        now += (T - l[i].fr) * l[i].sc;
    }
    int cur = 0;
    while(now > 0 && cur < h.size()) {
        if(now >= (h[cur].fr - T) * h[cur].sc) {
            now -= (h[cur].fr - T) * h[cur].sc;
            res += h[cur].sc;
            ++ cur;
        } else {
            res += (ld)now / (ld)(h[cur].fr - T);
            now = 0;
        }
    }
    //cerr << now << " " << res << endl;
    if(now == 0) {
        chmax(ans, tmp + res);
    }
    //
    res = 0.0; now = 0;
    rep(i, h.size()) {
        res += h[i].sc;
        now += (h[i].fr - T) * h[i].sc;
    }
    cur = 0;
    while(now > 0 && cur < l.size()) {
        if(now >= (T - l[cur].fr) * l[cur].sc) {
            now -= (T - l[cur].fr) * l[cur].sc;
            res += l[cur].sc;
            ++ cur;
        } else {
            res += (ld)now / (ld)(T - l[cur].fr);
            now = 0;
        }
    }
    //cerr << now << " " << res << endl;
    if(now == 0) {
        chmax(ans, tmp + res);
    }
    //
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}