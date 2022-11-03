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

int n;
vector<int> g[2020];
vector<int> c;
int root;
bool check;
int tmp;

vector<P> dfs(int v, int p) {
    vector<P> res;
    if(!check) return res;
    for(auto& nv: g[v]) {
        if(nv == p) continue;
        auto rec = dfs(nv, v);
        for(auto& x: rec) {
            res.push_back(x);
        }
    }
    ++tmp; //
    //
    sort(all(res));
    res.push_back({ tmp, -1});
    if(c[v] >= res.size()) {
        check = 0;
        cout << "NO" << endl;
        exit(0);
    }
    for(int i = (int)res.size() - 1; i > c[v]; --i) {
        res[i].sc = res[i - 1].sc;
    }
    res[c[v]].sc = v;
    return res;
}

void solve() {
	cin >> n;
    c.resize(n);
    vector<int> a(n);
    check = true;
    rep(i, n) {
        int p, x; cin >> p >> x;
        c[i] = x;
        --p;
        if(p != -1) {
            g[p].pb(i);
            g[i].pb(p);
        } else {
            root = i;
        }
    }
    auto res = dfs(root, -1);
    for(auto& x: res) {
        a[x.sc] = x.fr;
    }
    if(!check) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        rep(i, n) {
            cout << a[i] << " ";
        }
        cout << endl;
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