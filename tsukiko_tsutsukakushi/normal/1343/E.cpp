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

#define int long long
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

int n, m, a, b, c;
vector<int> p;
vector<vector<int>> g;

void solve() {
	cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    p.resize(m);
    g.assign(n, vector<int>());
    rep(i, m) {
        cin >> p[i];
    }
    sort(all(p));
    vector<int> sum(m + 1, 0);
    rep(i, m) {
        sum[i + 1] = sum[i] + p[i];
    }
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dist(n, inf);
    dist[b] = 0;
    queue<int> que;
    que.push(b);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv: g[v]) {
            if(chmin(dist[nv], dist[v] + 1)) {
                que.push(nv);
            }
        }
    }

    vector<int> dist1(n, inf);
    dist1[c] = 0;
    que.push(c);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv: g[v]) {
            if(chmin(dist1[nv], dist1[v] + 1)) {
                que.push(nv);
            }
        }
    }
    vector<int> dist2(n, inf);
    dist2[a] = 0;
    que.push(a);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nv: g[v]) {
            if(chmin(dist2[nv], dist2[v] + 1)) {
                que.push(nv);
            }
        }
    }
    int ans = INF;
    rep(i, n) {
        int co = dist[i] + dist1[i] + dist2[i];
        int co1 = dist[i];
        if(co > m) continue;
        //cerr << co << " " << co1 << endl;
        chmin(ans, sum[co] + sum[co1]);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}