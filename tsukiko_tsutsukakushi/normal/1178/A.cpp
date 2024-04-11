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
    vector<int> a(n);
    int sum = 0, tmp = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    tmp += a[0];
    vector<int> ans(1, 0);
    for(int i = 1; i < n; ++ i) {
        if(a[i] * 2 <= a[0]) tmp += a[i], ans.push_back(i);
    }
    if(tmp * 2 > sum) {
        cout << ans.size() << "\n";
        rep(i, ans.size()) {
            cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
        }
    } else {
        cout << 0 << "\n";
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