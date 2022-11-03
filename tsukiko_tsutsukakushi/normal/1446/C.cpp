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

const int inf = 1'000'000'007;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    auto dfs = [&](auto&& self, vector<int> s, int d) -> int {
        if(d < 0) return (int)s.size();
        vector<int> s0, s1;
        for(int x: s) {
            if(x & (1<<d)) s1.push_back(x);
            else s0.push_back(x);
        }
        if(s0.empty()) return self(self, s1, d - 1);
        if(s1.empty()) return self(self, s0, d - 1);
        // cerr << (int)s0.size() << " " << (int)s1.size() << "\n";
        return 1 + max(self(self, s0, d - 1), self(self, s1, d - 1));
    };
    cout << n - dfs(dfs, a, 31) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}