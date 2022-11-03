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

void solve() {
	int n, m, a, b; cin >> n >> m >> a >> b;
    vector<vector<int>> h(n, vector<int>(m));
    int g; cin >> g;
    int x, y, z; cin >> x >> y >> z;
    rep(i, n) {
        rep(j, m) {
            h[i][j] = g;
            g = (g * x + y) % z;
            // cerr << h[i][j] << " ";
        }
        // cerr << endl;
    }
    vector<vector<int>> t(n, vector<int>(m, 0));
    rep(i, n) {
        deque<pair<int, int>> deq;
        rep(j, b) {
            while(deq.size() and deq.back().fr >= h[i][j]) deq.pop_back();
            deq.push_back(P{h[i][j], j});
        }
        for(int j = 0; j + b <= m; ++ j) {
            while(deq.size() and deq.front().sc < j) deq.pop_front();
            t[i][j] = deq.front().fr;
            while(deq.size() and j + b < m and deq.back().fr >= h[i][j + b]) deq.pop_back();
            if(j + b < m) deq.push_back(P{h[i][j + b], j + b});
        }
    }
    ll ans = 0;
    for(int j = 0; j + b <= m; ++ j) {
        deque<pair<int, int>> deq;
        rep(i, a) {
            while(deq.size() and deq.back().fr >= t[i][j]) deq.pop_back();
            deq.push_back(P{t[i][j], i});
        }
        for(int i = 0; i + a <= n; ++ i) {
            while(deq.size() and deq.front().sc < i) deq.pop_front();
            ans += 1LL * deq.front().fr;
            while(deq.size() and i + a < n and deq.back().fr >= t[i + a][j]) deq.pop_back();
            if(i + a < n) deq.push_back(P{t[i + a][j], i + a});
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