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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(k), b(k);
    vector<int> ca(n, 0), cb(m, 0);
    rep(i, k) cin >> a[i];
    rep(i, k) cin >> b[i];
    rep(i, k) {
        -- a[i], -- b[i];
        ca[a[i]] ++, cb[b[i]] ++;
    }
    ll ans = 0;
    rep(i, k) {
        ans += (k - ca[a[i]] - cb[b[i]] + 1);
        //cerr << ca[a[i]] << " " << cb[b[i]] << " " << k - ca[a[i]] - cb[b[i]] + 1 << endl;
    }
    ans /= 2;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}