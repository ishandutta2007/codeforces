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

const int D = 3;

void solve() {
    int n; cin >> n;
    vector<vector<int>> p(n, vector<int>(D));
    rep(i, n) {
        rep(j, D) {
            cin >> p[i][j];
        }
    }
    auto dfs = [&](auto&& self, vector<int> ids, int d) {
        if(d == D) return ids[0];
        map<int, vector<int>> mp;
        for(int i: ids) {
            mp[p[i][d]].push_back(i);
        }
        vector<int> a;
        for(auto &q: mp) {
            int cur = self(self, q.sc, d + 1);
            if(cur != -1) a.push_back(cur);
        }
        for(int i = 0; i + 1 < (int)a.size(); i += 2) {
            cout << a[i] + 1 << " " << a[i + 1] + 1 << "\n";
        }
        return (a.size() % 2 == 1 ? a.back() : -1);
    };
    vector<int> ids(n);
    iota(all(ids), 0);
    dfs(dfs, ids, 0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}