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
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    auto check = [&](ld x) -> bool {
        rep(i, n) {
            // take off from i
            x -= (ld)(x + m) / (ld)a[i];
            if(x < 0.0) return false;
            // land on i + 1
            x -= (ld)(x + m) / (ld)b[(i + 1) % n];
            if(x < 0.0) return false;
        }
        return true;
    };
    ld ok = inf, ng = 0.0;
    if(!check(ok)) {
        cout << -1 << "\n";
        return;
    }
    rep(_, 200) {
        ld mid = (ok + ng) / 2.0;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}