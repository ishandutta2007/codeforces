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

const int MAX = 100;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(MAX + 1, 0);
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int d = -1, tmp = -1;
    for(int i = 1; i <= MAX; ++ i) {
        if(chmax(tmp, cnt[i])) d = i;
    }
    int ans = 0;
    const int inf = 1'000'000'007;
    vector<int> mp(2 * n + 1, inf);
    for(int v = 1; v <= 100; ++ v) {
        if(v == d) continue;
        mp.assign(2 * n + 1, inf);
        mp[0 + n] = 0;
        int cv = 0, cd = 0;
        rep(i, n) {
            if(a[i] == v) ++ cv;
            if(a[i] == d) ++ cd;
            if(mp[cv - cd + n] != inf) chmax(ans, i + 1 - mp[cv - cd + n]);
            else mp[cv - cd + n] = i + 1;
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}