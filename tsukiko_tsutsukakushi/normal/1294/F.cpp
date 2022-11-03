/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
vector<vector<int>> g;

pair<int, int> dfs(int v, int p, vector<int> &prev) {
    pair<int, int> res(v, 0);
    rep(i, (int)g[v].size()) {
        if(g[v][i] == p) continue;
        pair<int ,int> tmp = dfs(g[v][i], v, prev);
        tmp.sc ++;
        if(tmp.sc > res.sc) {
            res = tmp;
            prev[g[v][i]] = v;
        }
    }
    return res;
}

vector<int> diameter() {
    vector<int> prev;
    prev.assign(n, -1);
    pair<int, int> leaf = dfs(0, -1, prev);
    prev.assign(n, -1);
    pair<int, int> t = dfs(leaf.fr, -1, prev);
    vector<int> res;
    int cur = t.fr;
    while(cur != -1) {
        res.push_back(cur);
        cur = prev[cur];
    }
    return res;
}

void solve() {
	cin >> n;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto res = diameter();
    int a = res.front(), b = res.back();
    queue<int> que;
    vector<int> dist(n, -1);
    for(auto v: res) {
        dist[v] = 0;
        que.push(v);
    }
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(auto nu: g[u]) {
            if(dist[nu] == -1) {
                dist[nu] = dist[u] + 1;
                que.push(nu);
            }
        }
    }
    if(res.size() == n) {
        int c = -1;
        rep(i, n) {
            if(i == a || i == b) continue;
            c = i;
        }
        cout << n - 1 << endl << a + 1 << " " << b + 1 << " " << c + 1 << endl;
        return;
    }
    int c = -1, di = 0;
    rep(i, n) {
        if(i == a || i == b) continue;
        if(di < dist[i]) {
            di = dist[i];
            c = i;
        }
    }
    int ans = (int)res.size() - 1 + dist[c];
    cout << ans << endl << a + 1 << " " << b + 1 << " " << c + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}