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
    bool check0 = 0;
    vector<vector<int>> g(n, vector<int>());
    rep(i, n) {
        cin >> a[i]; -- a[i];
        g[a[i]].push_back(i);
        if(a[i] == 0) check0 = 1;
    }
    vector<int> ans(n + 1, 0);
    auto c = a;
    sort(all(c));
    bool check1 = 1;
    rep(i, n) if(c[i] != i) check1 = 0;
    ans[1] = (check1 ? 1 : 0);
    ans[n] = (check0 ? 1 : 0);
    int l = -1, r = n;
    for(int k = n - 1; k >= 1; -- k) {
        int num = n - 1 - k;
        if(g[num].size() >= 2 or g[num].size() == 0) break;
        int pos = g[num][0];
        if(g[num + 1].size() == 0) break;
        if(pos == l + 1) {
            ans[k] = 1;
            ++ l;
            continue;
        }
        if(pos == r - 1) {
            ans[k] = 1;
            -- r;
            continue;
        }
        break;
    }
    for(int k = 1; k <= n; ++ k) cout << ans[k];
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}