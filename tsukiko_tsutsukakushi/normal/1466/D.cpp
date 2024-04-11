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
    vector<int> w(n);
    ll sum = 0;
    rep(i, n) {
        cin >> w[i];
        sum += w[i];
    }
    vector<vector<int>> g(n, vector<int>());
    vector<int> deg(n, 0);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; -- u, -- v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++ deg[u], ++ deg[v];
    }
    vector<int> c;
    rep(i, n) {
        rep(j, deg[i] - 1) {
            c.push_back(w[i]);
        }
    }
    sort(all(c), greater<int>());
    ll now = sum;
    rep(i, n - 1) {
        cout << now << " ";
        if(i < n - 2) now += c[i];
    } 
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