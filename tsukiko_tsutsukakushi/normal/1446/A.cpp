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
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; ll W; cin >> n >> W;
    vector<P> w(n);
    ll sum = 0;
    rep(i, n) {
        cin >> w[i].fr;
        w[i].sc = i;
        sum += w[i].fr;
    }
    if(sum < (W + 1) / 2) {
        cout << -1 << endl;
        return;
    }
    sort(all(w));
    reverse(all(w));
    vector<int> ans;
    ll now = 0;
    rep(i, n) {
        if(now + w[i].fr <= W) {
            now += w[i].fr;
            ans.push_back(w[i].sc);
        }
    }
    if(now < (W + 1) / 2) {
        cout << -1 << endl;
        return;
    }
    cout << (int)ans.size() << endl;
    rep(i, (int)ans.size()) {
        cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}