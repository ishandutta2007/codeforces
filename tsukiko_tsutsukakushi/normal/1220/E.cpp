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
#define debug(x)  cout << #x << " = " << (x) << endl;
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

//
//s

int n, m; 
Graph G;

vector<ll> dist;
vector<int> deg;
vector<ll> w;

void dfs(int v) {
    for(auto nv: G[v]) {
        if(dist[nv] == -1) {
            dist[nv] = dist[v] + w[nv];
            dfs(nv);
        }
    }
}

void solve() {
	cin >> n >> m;
    G.assign(n, vector<int>());
    dist.assign(n, -1);
    deg.assign(n, 0);
    w.assign(n, 0);
    rep(i, n) {
        cin >> w[i];
    }
    rep(i, m) {
        int a, b; cin >> a >> b; --a; --b;
        G[a].pb(b); G[b].pb(a);
        ++deg[a]; ++deg[b];
    }
    int s; cin >> s; --s;

    queue<int> que;
    rep(i, n) {
        if(i != s && deg[i] == 1) que.push(i);
    }
    vector<bool> ispushed(n, false);

    while(!que.empty()) {
        int v = que.front(); que.pop();
        ispushed[v] = true;
        for(auto nv: G[v]) {
            --deg[nv];
            if(nv != s && deg[nv] == 1) que.push(nv);
        }
    }
    
    //1 //
    //dfs
    
    ll res = 0;
    rep(i, n) {
        if(!ispushed[i]) {
            res += w[i];
            dist[i] = 0;
        }
    }
    
    rep(i, n) {
        if(!ispushed[i]) {
            dfs(i);
        }
    }
    ll ma = 0;
    rep(i, n) {
        chmax(ma, dist[i]);
    }
    cout << res + ma << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}