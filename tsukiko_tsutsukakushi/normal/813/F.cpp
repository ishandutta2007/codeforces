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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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

int n, q;
vector<vector<int>> vec;
map<pair<int, int>, int> mp;
vector<int> ans;

struct UnionFind {
    vector<int> par;
    vector<vector<int>> hist;

    UnionFind(int n) : par(n, -1) {}
    int root(int x) {
        if(par[x] < 0) return x;
        return root(par[x]);
    }
    void pop() {
        if(hist.size()) {
            auto a = hist.back();
            hist.pop_back();
            par[a[0]] = a[1];
            par[a[2]] = a[3];
        }
    }
    bool merge(int x, int y) {
        x = root(x), y = root(y);
        hist.push_back({x, par[x], y, par[y]});
        if(x == y) return false;
        if(par[x] > par[y]) {
            par[y] += par[x];
            par[x] = y;
        } else {
            par[x] += par[y];
            par[y] = x;
        }
        return true;
    }
};

void dfs(int l, int r, UnionFind& uf, vector<vector<int>> vec) {
    vector<vector<int>> lv, rv;
    int nums = 0;
    int mid = (l + r) / 2;
    int check = 1;
    
    if(vec.empty()) return;

    for(auto a: vec) {
        if(a[2] <= l and r <= a[3]) {
            uf.merge(a[0], a[1] + n);
            uf.merge(a[0] + n, a[1]);
            if(uf.root(a[0]) == uf.root(a[0] + n)) check = 0;
            if(uf.root(a[1]) == uf.root(a[1] + n)) check = 0;
            nums += 2;
        } else {
            if(a[2] < mid) lv.push_back({a[0], a[1], max(l, a[2]), min(a[3], mid)});
            if(a[3] > mid) rv.push_back({a[0], a[1], max(mid, a[2]), min(r, a[3])});
        }
    }

    if(!check) {
        // cerr << l << " " << r << endl;
        for(int i = l; i < r; ++ i) ans[i] = 0;
    } else {
        dfs(l, mid, uf, lv);
        dfs(mid, r, uf, rv);
    }
    while(nums--) uf.pop(); 
}

void solve() {
	cin >> n >> q;
    ans.assign(q, true);
    rep(i, q) {
        int x, y; cin >> x >> y; -- x, -- y;
        if(x > y) swap(x, y);
        if(mp.count({x, y}) == 0) {
            mp[{x, y}] = i;
        } else {
            vec.push_back({x, y, mp[{x, y}], i});
            mp.erase({x, y});
        }
    }
    for(auto p: mp) {
        vec.push_back({p.fr.fr, p.fr.sc, p.sc, q});
    }
    UnionFind uf(n * 2);
    dfs(0, q, uf, vec);
    rep(i, q) {
        cout << (ans[i] ? "YES" : "NO") << endl;
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