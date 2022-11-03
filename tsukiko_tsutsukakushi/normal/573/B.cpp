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
    int n; cin >> n;
    vector<int> h(n + 2, 0);
    rep(i, n) {
        cin >> h[i + 1];
    }
    vector<int> m(n + 2), p(n + 2);
    rep(i, n + 2) {
        m[i] = h[i] - i;
        p[i] = h[i] + i;
    }
    vector<int> res(n + 2);
    int worst = inf;
    rep(i, n + 2) {
        chmin(worst, m[i]);
        res[i] = worst + i;
    }
    worst = inf;
    per(i, n + 2) {
        chmin(worst, p[i]);
        chmin(res[i], worst - i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        chmax(ans, res[i]);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}