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
	int n;
    cin >> n;
    vector<ll> a(n);
    ll e = 0, o = 0;
    rep(i, n) {
        cin >> a[i];
        if(i % 2 == 0) e += a[i];
        else o += a[i];
    }
    auto b = a;
    rep(i, n) {
        if(i % 2 == 0 and o >= e) b[i] = 1;
        if(i % 2 == 1 and e > o) b[i] = 1;
    } 
    rep(i, n) {
        cout << b[i] << " \n"[i == n - 1];
    }
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}