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

int n, k;
vector<set<int>> g;
vector<set<int>> leaves;

void solve() {
	cin >> n >> k;
    g.assign(n, set<int>());
    leaves.assign(n, set<int>());
    rep(i, n - 1) {
        int x, y; cin >> x >> y;
        -- x, -- y;
        g[x].insert(y);
        g[y].insert(x);
    }
    if(k == 1) {
        cout << n - 1 << endl;
        return;
    }
    rep(i, n) {
        if(g[i].size() == 1) {
            leaves[*g[i].begin()].insert(i);
        }
    }
    queue<int> que;
    rep(i, n) {
        if(leaves[i].size() >= k) que.push(i);
    }
    int ans = 0;
    while(que.size()) {
        int v = que.front(); que.pop();
        // cerr << "v = " << v << endl;
        if(leaves[v].size() < k) continue;
        ++ ans;
        rep(i, k) {
            int nv = *leaves[v].begin();
            g[nv].erase(v);
            g[v].erase(nv);
            leaves[nv].erase(v);
            if(leaves[v].count(nv)) leaves[v].erase(nv);
        }
        if(leaves[v].size() >= k) {
            que.push(v);
        }
        if(g[v].size() == 1) {
            leaves[*g[v].begin()].insert(v);
            if(leaves[*g[v].begin()].size() >= k) {
                que.push(*g[v].begin());
            }
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}