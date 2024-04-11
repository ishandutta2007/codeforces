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
    const int MAX = 2000;
    vector<ll> p(MAX + 1, 0);
    vector<ll> pw(MAX + 1, 1LL);
    rep(i, MAX) {
        pw[i + 1] = pw[i] * 2LL;
    }
    for(int i = 1; i <= MAX; ++ i) {
        p[i] = i;
        for(int j = 1; j <= i; ++ j) {
            p[i] += j * pw[i - j];
        }
    }
    // rep(i, 60) {
    //     cerr << p[i] << " \n"[i == 59];
    // }
    // 60ok
    int t; cin >> t;
    rep(_, t) {
        ll k; cin >> k;
        if(k % 2 == 1) {
            cout << -1 << "\n";
        } else {
            vector<int> ans(1, 1);
            k -= 2;
            ll cur = 59;
            while(k > 0) {
                if(k >= p[cur]) {
                    k -= p[cur];
                    rep(i, cur - 1) ans.push_back(0);
                    ans.push_back(1);
                } else {
                    -- cur;
                }
            }
            cout << ans.size() << "\n";
            rep(i, ans.size()) {
                cout << ans[i] << " \n"[i == (int)ans.size() - 1];
            }
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	// int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}