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
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

pair<int, int> f(int a) {
    if(a % 42 == 0) {
        return {42, a / 42};
    }
    if(a % 23 == 0) {
        return {23, a / 23};
    }
    if(a % 15 == 0) {
        return {15, a / 15};
    }
    if(a == 32) {
        return {4, 8};
    }
    if(a == 64) {
        return {4, 16};
    }
    if(a == 128) {
        return {8, 16};
    }
}

void solve() {
	int x[4];
    rep(i, 4) {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        fflush(stdout);
        cin >> x[i];
    }
    int ans[6];
    for(int i = 1; i <= 3; ++i) {
        P a = f(x[i - 1]), b = f(x[i]);
        //cerr << a.fr << " " << a.sc << endl;
        if(a.fr == b.fr) {
            ans[i] = a.fr;
        } else if(a.fr == b.sc) {
            ans[i] = a.fr;
        } else if(a.sc == b.fr || a.sc == b.sc) {
            ans[i] = a.sc;
        }
    }
    P c = f(x[0]);
    if(c.fr == ans[1]) {
        ans[0] = c.sc;
    } else {
        ans[0] = c.fr;
    }
    P d = f(x[3]);
    if(d.fr == ans[3]) {
        ans[4] = d.sc;
    } else {
        ans[4] = d.fr;
    }
    set<int> se;
    se.insert(4), se.insert(8), se.insert(15), se.insert(16), se.insert(23), se.insert(42);
    rep(i, 5) {
        se.erase(ans[i]);
    }    
    ans[5] = *se.begin();
    cout << "! ";
    rep(i, 6) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}