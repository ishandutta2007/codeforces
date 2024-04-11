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

struct UnionFind {
    int s, t;
    vector<int> par;
    vector<int> cnt;

    UnionFind(int n) : s(n), t(2 * n + 1), par(2 * n + 2, -1), cnt(2 * n + 2, 0) {
        for(int i = n + 1; i < 2 * n + 1; ++ i) {
            cnt[i] = 1;
        }
        cnt[2 * n + 1] = INF;
    }

    int root(int x) {
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        cnt[x] += cnt[y];
        par[x] += par[y];
        par[y] = x;
        return true; 
    }

    int size(int x) {
        return -par[root(x)];
    }

    int get_cnt(int x) {
        return cnt[root(x)];
    }
};

void solve() {
	int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> g(n, vector<int>());
    rep(i, k) {
        int c; cin >> c;
        rep(j, c) {
            int a; cin >> a; -- a;
            g[a].push_back(i);
        }
    }
    UnionFind uf(k);
    int ans = 0;

    //x01
    auto get = [&](int x) {
        x %= (k + 1);
        return min(uf.get_cnt(x), uf.get_cnt(x + k + 1));
    };

    auto merge = [&](int x, int y) {
        if(uf.issame(x, y)) return;
        int pre = get(x) + get(y);
        uf.merge(x, y);
        if(x < k + 1) x += k + 1; else x -= (k + 1);
        if(y < k + 1) y += k + 1; else y -= (k + 1);
        uf.merge(x, y);
        int cur = get(x);
        // cerr << x << " " << y << endl;
        // cerr << pre << " " << cur << endl;
        // cerr << uf.get_cnt(3) << endl;
        ans += cur - pre;
    };

    rep(i, n) {
        int w = (s[i] == '0' ? 1 : 0);
        if(g[i].size() == 1) {
            int x = g[i][0];
            if(w == 0) merge(x, uf.s);
            else merge(x + k + 1, uf.s);
        } else if(g[i].size() == 2) {
            int x = g[i][0], y = g[i][1];
            if(w == 0) merge(x, y);
            else merge(x, y + k + 1);
        }
        // cerr << i << " " << w << " " << g[i].size() << endl; 
        // rep(j, 2 * k + 2) {
        //     cerr << j << " " << uf.root(j) << " " << uf.cnt[j] << endl;
        // }
        cout << ans << endl;
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