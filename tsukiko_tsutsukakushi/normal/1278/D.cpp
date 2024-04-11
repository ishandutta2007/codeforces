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
//#define int long long

struct UnionFind {
    vector<int> par, w;
    
    UnionFind(int n) : par(n, -1), w(n, 0) { }
    void init(int n) { par.assign(n, -1); w.assign(n, 0); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }
};

using vertice = pair<pair<int, int>, int>;

void solve() {
	int n; cin >> n;
    vector<vertice> vs(n);
    set<int> sel;
    map<int, int> mp;
    rep(i, n) {
        int x, y; cin >> x >> y;
        sel.insert(x);
        mp[x] = i;
        mp[y] = i;
        vs[i] = make_pair(make_pair(x, y), i);
    }
    // bool used[500500];
    // rep(i, 500500) {
    //     used[i] = 0;
    // }
    UnionFind uf(n);
    set<P> se;
    int cnt = 0;
    for(int i = 1; i <= 2 * n; ++i) {
        int j = mp[i];
        if(sel.count(i)) {
            for(auto& p: se) {
                int k = p.sc;
                if(vs[j].fr.sc < vs[k].fr.sc) break; ////ABC139E League
                if(uf.issame(j, k)) {
                    cout << "NO" << endl;
                    return;
                } else {
                    uf.merge(j, k);
                    ++cnt;
                    //used[j] = used[k] = 1;
                }
            }
            se.insert(make_pair(vs[j].fr.sc, j));
        } else {
            se.erase(make_pair(vs[j].fr.sc, j));
        }
    }
    // rep(i, n) {
    //     if(!used[i]) {
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }
    if(uf.size(0) != n || cnt != n - 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}