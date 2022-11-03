/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
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
    vector<int> cnt(n, 1);
    rep(i, n) {
        cin >> a[i]; -- a[i];
    }
    vector<int> b = {a[0]};
    for(int i = 1; i < n; ++ i) {
        if(a[i - 1] != a[i]) {
            b.push_back({a[i]});
        }
    }
    int m = (int)b.size();
    rep(i, m) {
        cnt[b[i]] ++;
    }
    cnt[b[0]] --, cnt[b[m - 1]] --;
    int ans = n + 1;
    rep(i, n) {
        chmin(ans, cnt[a[i]]);
    }
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