/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
void solve() {
	int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        cin >> b[i];
    }
    vector<ll> c(n - 1);
    rep(i, n - 1) {
        c[i] = a[i + 1] - a[i];
        c[i] = abs(c[i]);
    }
    ll g = 0;
    rep(i, n - 1) {
        g = __gcd(g, c[i]);
    }
    rep(i, m) {
        cout << __gcd(g, a[0] + b[i]) << " \n"[i == m - 1];
    }
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}