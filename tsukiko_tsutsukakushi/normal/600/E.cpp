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
vector<int> c;
vector<vector<int>> g;
vector<int> ans;

void rec(int v, int par, map<int, int> &counter, int &mean, int &sum) {
    counter.clear();
    counter[c[v]] ++;
    mean = 1;
    sum = c[v];
    for(auto nv: g[v]) {
        if(nv == par) continue;
        map<int, int> ch_counter;
        int ch_mean;
        int ch_sum;
        rec(nv, v, ch_counter, ch_mean, ch_sum);
        //
        if(ch_counter.size() > counter.size()) {
            // if(chmax(mean, ch_mean)) sum = ch_sum;
            // else if(mean == ch_mean) sum += ch_sum;
            swap(ch_counter, counter);
            swap(ch_sum, sum);
            swap(ch_mean, mean);
        }
        for(auto p: ch_counter) {
            counter[p.fr] += p.sc;
            if(chmax(mean, counter[p.fr])) sum = p.fr;
            else if(mean == counter[p.fr]) sum += p.fr;
        }
    }
    ans[v] = sum;
}

void solve() {
	cin >> n;
    c.resize(n);
    g.assign(n, vector<int>());
    ans.resize(n);
    rep(i, n) {
        cin >> c[i];
    }
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int, int> counter;
    int mean, sum;
    rec(0, -1, counter, mean, sum);
    rep(i, n) {
        if(i) cout << " ";
        cout << ans[i];
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