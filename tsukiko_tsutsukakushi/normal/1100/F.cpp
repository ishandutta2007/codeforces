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
vector<int> c;
int q;
vector<int> l, r;
vector<int> ret;
vector<int> P[505050];

vector<int>& add(vector<int>& t, int a) {
    for(int e: t) chmin(a, a ^ e);
    if(a) t.push_back(a);
    return t; 
}

void dfs(int le, int ri, vector<int>& v) {
    if(v.empty()) return;
    if(le + 1 == ri) {
        for(int e: v) ret[e] = c[le];
        return;
    }
    int mi = (ri + le) / 2;
    vector<int> a[3];
    for(int e: v) {
        if(r[e] <= mi) a[0].push_back(e);
        else if(mi <= l[e]) a[1].push_back(e);
        else a[2].push_back(e);
    }
    if(a[2].size()) {
        vector<int> t;
        for(int i = mi; i >= le; -- i) {
            P[i] = add(t, c[i]);
        }
        t.clear();
        for(int i = mi; i < ri; ++ i) {
            P[i] = add(t, c[i]);
        }
        for(int e: a[2]) {
            vector<int> basis = P[l[e]];
            for(int b: P[r[e] - 1]) {
                add(basis, b);
            }
            for(int b: basis) {
                chmax(ret[e], ret[e] ^ b);
            }
        }
    }
    dfs(le, mi, a[0]);
    dfs(mi, ri, a[1]);
}

void solve() {
	cin >> n;
    c.resize(n);
    rep(i, n) {
        cin >> c[i];
    }
    cin >> q;
    ret.assign(q, 0);
    l.resize(q); r.resize(q);
    vector<int> v;
    rep(i, q) {
        cin >> l[i] >> r[i];
        -- l[i];
        v.push_back(i);
    }
    dfs(0, n, v);
    rep(i, q) {
        cout << ret[i] << endl;
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