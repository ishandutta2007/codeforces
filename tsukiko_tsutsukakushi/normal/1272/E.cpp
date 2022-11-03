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

int n;
vector<int> a;
vector<vector<int>> g;

void bfs(vector<int> st, vector<int> &f) {
    queue<int> que;
    for(auto v: st) {
        f[v] = 0;
        que.push(v);
    }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(auto nv: g[v]) {
            if(f[nv] == INF) {
                f[nv] = f[v] + 1;
                que.push(nv);
            }
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    g.assign(n, vector<int>());
    vector<int> d(n, INF), e(n, INF);
    vector<int> odd, even;
    rep(i, n) {
        cin >> a[i];
        if(0 <= i - a[i]) {
            //g[i].push_back(i - a[i]);
            g[i - a[i]].push_back(i);
        }
        if(i + a[i] < n) {
            //g[i].push_back(i + a[i]);
            g[i + a[i]].push_back(i);
        }
        if(a[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    bfs(even, d);
    bfs(odd, e);
    rep(i, n) {
        if(a[i] % 2 == 0) {
            if(e[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << e[i] << " ";
            }
        } else {
            if(d[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << d[i] << " ";
            }
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}