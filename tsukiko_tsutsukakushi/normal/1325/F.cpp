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

int n, m, sq;
vector<vector<int>> g;
vector<int> dep;
vector<bool> marked;

vector<int> s;

void dfs(int v) {
    dep[v] = (int)s.size();
    s.push_back(v);
    for(int u: g[v]) {
        if(dep[u] == -1) dfs(u);
        //
        else if(dep[v] - dep[u] >= sq - 1) {
            cout << 2 << endl;
            cout << dep[v] - dep[u] + 1 << endl;
            for(int i = dep[v]; i >= dep[u]; --i) {
                cout << s[i] + 1 << " ";
            }
            cout << endl;
            exit(0);
        }
    }
    //
    if(marked[v]) {
        for(int u: g[v]) {
            marked[u] = 0;
        }
    }
    s.pop_back();
}

void solve() {
	cin >> n >> m;
    sq = 1;
    while(sq * sq < n) ++sq;
    g.assign(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dep.assign(n, -1);
    marked.assign(n, 1);
    //cerr << sq << endl;
    dfs(0);

    cout << 1 << endl;
    rep(i, n) {
        if(sq && marked[i]) {
            sq --;
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}