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

int n, m, q;
vector<int> p;
vector<pair<int, int>> es;

struct UnionFind {
    int n;
    vector<int> par;
    vector<set<int>> nums;
    vector<array<int, 4>> add;
    // vector<set<int>> addp;
    vector<bool> ers;

    UnionFind(int n_) : n(n_), par(n_, -1), nums(n_, set<int>()), ers(n_ + 1, false){ 
        rep(i, n_) {
            nums[i].insert(p[i]);
        }
    }

    int root(int x) {
        if(par[x] < 0) return x;
        return root(par[x]);
    }

    void pop() {
        if(add.size()) {
            auto ad = add.back();
            add.pop_back();
            if(ad[0] == -1) {
                return;
            }
            par[ad[0]] = ad[1], par[ad[2]] = ad[3];
            for(auto ite = nums[ad[2]].begin(); ite != nums[ad[2]].end();) {
                if(ers[*ite]) {
                    ite = nums[ad[2]].erase(ite);
                    continue;
                }
                nums[ad[0]].erase(*ite); 
                ++ ite;
            }
            // auto adp = addp.back();
            // addp.pop_back();
            // for(int z: adp) {
            //     // cerr << ad[0] << " " << ad[2] << " " << z << endl;
            //     if(ers[z]) {
            //         // cerr << "ers" << z << endl;
            //         nums[ad[2]].erase(z);
            //     }
            //     nums[ad[0]].erase(z);
            // }
        }
    }

    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) {
            add.push_back({-1, -1, -1, -1});
            return false;
        }
        if(par[x] > par[y]) swap(x, y);
        add.push_back({x, par[x], y, par[y]});
        // set<int> adp;
        for(int z: nums[y]) {
            nums[x].insert(z);
            // adp.insert(z);
        }
        // addp.push_back(adp);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int ans(int x) {
        x = root(x);
        if(nums[x].empty()) {
            return 0;
        }
        auto ite = nums[x].end(); 
        -- ite;
        ers[(*ite)] = true;
        nums[x].erase(*ite);
        // cerr << x << " " << *ite << endl;
        return *ite;
    }
};

void solve() {
	cin >> n >> m >> q;
    p.resize(n);
    rep(i, n) {
        cin >> p[i];
    }
    es.resize(m);
    rep(i, m) {
        int a, b; cin >> a >> b;
        -- a, -- b;
        es[i] = {a, b};
    }
    vector<int> t(q), v(q, -1), id(q, -1);
    vector<bool> used(m, 0);
    rep(i, q) {
        cin >> t[i];
        if(t[i] == 1) {
            cin >> v[i];
            -- v[i];
        }
        else {
            cin >> id[i];
            -- id[i];
            used[id[i]] = 1;
        }
    }
    UnionFind uf(n);
    rep(i, m) {
        if(!used[i]) {
            uf.merge(es[i].fr, es[i].sc);
        }
    }
    per(i, q) {
        if(t[i] == 2) {
            uf.merge(es[id[i]].fr, es[id[i]].sc);
        }
    }
    rep(i, q) {
        if(t[i] == 1) {
            cout << uf.ans(v[i]) << endl;
        } else {
            uf.pop();
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