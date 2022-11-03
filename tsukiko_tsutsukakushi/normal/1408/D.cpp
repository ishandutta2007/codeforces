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

// #define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int INF=1e9+7;
// const ll INF=1LL<<60 ;
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

int n, m;
int a[2020], b[2020], c[2020], d[2020];
// map<int, int> mp;

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
	cin >> n >> m;
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    rep(i, m) {
        cin >> c[i] >> d[i];
    }
    // rep(i, n) {
    //     rep(j, m) {
    //         int x = c[j] - a[i], y = d[j] - b[i];
    //         if(mp.count(x)) {
    //             chmax(mp[x], y);
    //         } else {
    //             mp[x] = y;
    //         }
    //     }
    // }
    // vector<int> comx;
    // for(auto p: mp) {
    //     comx.emplace_back(p.fr);
    // }
    vector<int> xs;
    rep(i, n) {
        rep(j, m) {
            xs.emplace_back(c[j] - a[i]);
        }
    }
    auto comx = compress(xs);
    int sz = (int)comx.size();
    vector<int> cy(sz, -INF);
    rep(i, n) {
        rep(j, m) {
            int x = c[j] - a[i], y = d[j] - b[i];
            int k = lower_bound(all(comx), x) - comx.begin();
            chmax(cy[k], y);
        }
    }
    per(i, sz) {
        // chmax(cy[i], mp[comx[i]]);
        if(i + 1 < sz) chmax(cy[i], cy[i + 1]);
    }
    int ans = INF;
    rep(i, sz) {
        int xx = comx[i], yy = cy[i];
        int nxty = (i + 1 < sz ? max(0, cy[i + 1] + 1) : 0LL);
        int nxtx = max(0, xx + 1);
        chmin(ans, nxtx + nxty);
    }
    chmin(ans, max(0, comx[sz - 1] + 1));
    if(comx[0] >= 0) {
        // chmin(ans, max(0, mp[comx[0]] + 1));
        chmin(ans, max(0, cy[0] + 1));
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