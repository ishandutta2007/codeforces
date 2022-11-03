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
    int n, k; cin >> n >> k;
    vector<int> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    vector<int> dpmi(n, 0), dpma(n, 0);
    dpmi[0] = h[0], dpma[0] = h[0];
    for(int i = 1; i < n; ++ i) {
        dpmi[i] = dpmi[i - 1] - (k - 1);
        dpma[i] = dpma[i - 1] + (k - 1);
        if(dpma[i] < h[i] or h[i] + (k - 1) < dpmi[i]) {
            cout << "NO\n";
            return;
        }
        chmin(dpma[i], h[i] + (k - 1));
        chmax(dpmi[i], h[i]);
    }
    if(dpmi[n - 1] <= h[n - 1] and h[n - 1] <= dpma[n - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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