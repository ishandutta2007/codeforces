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

int n, m;
vector<vector<int>> g;
int k;
vector<int> p;

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    vector<vector<int>> h(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v;
        --u; --v;
        //g[u].pb(v);
        h[u].pb(v);
        g[v].pb(u);
    }
    cin >> k;
    p.resize(k);
    rep(i, k) {
        cin >> p[i];
        -- p[i];
    }
    vector<int> d(n, INF);
    priority_queue<P, vector<P>, greater<P>> pque;
    pque.push({0, p[k - 1]});
    d[p[k - 1]] = 0;
    while(pque.size()) {
        P q = pque.top(); pque.pop();
        int to = q.sc, di = q.fr;
        if(d[to] < di) continue;
        for(auto e: g[to]) {
            if(chmin(d[e], d[to] + 1)) {
                pque.push({d[e], e});
            }
        }
    }
    rep(i, k) {
        cerr << d[p[i]] << " ";
    }
    cerr << endl;
    int mi = 0, ma = 0;
    rep(i, k - 1) {
        if(d[p[i]] < d[p[i + 1]] + 1) {
            ++ mi; ++ma;
        } else {
            int cnt = 0;
            int di = d[p[i + 1]];
            for(auto e: h[p[i]]) {
                if(di == d[e]) ++cnt;
            }
            if(cnt >= 2) {
                ++ ma;
            }
        }
    }
    cout << mi << " " << ma << endl; 
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}