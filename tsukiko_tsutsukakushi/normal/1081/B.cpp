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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        cnt[n - a[i]] ++;
    }
    for(int i = 1; i <= n; ++ i) {
        if(cnt[i] % i != 0) {
            cout << "Impossible\n";
            return;
        }
    }
    cout << "Possible\n";
    int id = 1;
    vector<int> res(n + 1);
    iota(all(res), 0);
    map<int, int> mp;
    rep(i, n) {
        if(res[n - a[i]] == n - a[i]) {
            cout << id << " ";
            mp[n - a[i]] = id, -- res[n - a[i]];
            if(res[n - a[i]] == 0) res[n - a[i]] = n - a[i];
            ++ id;
        } else {
            cout << mp[n - a[i]] << " ";
            -- res[n - a[i]];
            if(res[n - a[i]] == 0) res[n - a[i]] = n - a[i];
        }
    }
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}