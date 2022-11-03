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

int n, k;
vector<vector<int>> g;
vector<int> pre;

void dfs(int v, int p, vector<int>& dist, int d) {
    dist[v] = d;
    pre[v] = p;
    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v, dist, d + 1);
    }
}

void fail() {
    cout << "No" << endl;
    exit(0);
}

void solve() {
	cin >> n >> k;
    g.assign(n, vector<int>());
    vector<int> deg(n, 0);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
        ++ deg[u], ++ deg[v];
    }
    vector<int> dist(n, -1);
    pre.assign(n, -1);
    dfs(0, -1, dist, 0);
    int r = -1, res = -1;
    rep(i, n) {
        if(chmax(res, dist[i])) r = i;
    }
    dfs(r, -1, dist, 0);
    int gg = -1; res = -1;
    rep(i, n) {
        if(chmax(res, dist[i])) gg = i;
    }
    if(dist[gg] % 2 != 0) {
        fail();
    }
    int ra = dist[gg] / 2;
    if(ra != k) fail();
    int ce = gg;
    rep(i, ra) ce = pre[ce];
    //cerr << ce << " " << ra << endl;
    if(deg[ce] < 3) fail();
    queue<int> que;
    que.push(ce);
    vector<bool> used(n, 0);
    bool check = 0;
    while(que.size()) {
        int v = que.front(); que.pop();
        used[v] = 1;
        for(int nv: g[v]) {
            if(!used[nv]) {
                if(deg[nv] >= 4) {
                    if(check) fail();
                }
                else if(deg[nv] == 1) {
                    check = 1;
                } else {
                    fail();
                }
                que.push(nv);
            }
        }
    }
    cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}