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
	int n, l; cin >> n >> l;
    vector<int> a(n + 2, 0);
    rep(i, n) {
        cin >> a[i + 1];
    }
    a[n + 1] = l;
    vector<ld> tl(n + 2, 0.0), tr(n + 2, 0.0);
    for(int i = 1; i < n + 2; ++ i) {
        tl[i] = tl[i - 1] + (ld)(a[i] - a[i - 1]) / (ld)i;
        // cerr << tl[i] << endl;
    }
    for(int i = n; i >= 0; -- i) {
        tr[i] = tr[i + 1] + (ld)(a[i + 1] - a[i]) / (ld)(n + 1 - i);
        // cerr << tr[i] << endl;
    }
    rep(i, n + 2) {
        if(tl[i] > tr[i]) {
            if(tl[i - 1] < tr[i]) {
                ld dist = (ld)(a[i] - (ld)(a[i - 1] + (ld)i * (ld)(tr[i] - tl[i - 1])));
                cout << (ld)tr[i] + (ld)dist / (ld)(i + n + 2 - i) << endl; 
            } else {
                ld dist = (ld)((ld)(a[i] - (ld)(n + 2 - i) * (ld)abs(tr[i] - tl[i - 1])) - a[i - 1]);
                cout << (ld)tl[i - 1] + (ld)dist / (ld)(i + n + 2 - i) << endl; 
            }
            // ld dist = (a[i] - a[i - 1]);
            // cerr << i << " " << a[i] << " " << a[i - 1] << " " << dist << endl;
            // cout << (ld)tl[i - 1] + (ld)dist / (ld)(i + n + 2 - i) << endl; 
            return;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}