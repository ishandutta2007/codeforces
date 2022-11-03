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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    map<ll, bool> mp;
    auto rec = [&](auto &&self, vector<ll> x) -> void {
        vector<ll> left, right;
        ll ma = *max_element(all(x)), mi = *min_element(all(x));
        ll mid = (ma + mi) / 2;
        ll sum = 0;
        for(auto e: x) {
            sum += e;
            if(e <= mid) left.emplace_back(e);
            else right.emplace_back(e);
        }
        mp[sum] = true;
        if(left.empty() or right.empty()) return;
        self(self, left);
        self(self, right);
    };
    rec(rec, a);
    rep(i, q) {
        ll s; cin >> s;
        if(mp[s]) cout << "Yes\n";
        else cout << "No\n";
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