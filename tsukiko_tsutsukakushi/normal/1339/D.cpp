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
vector<vector<int>> g;
vector<int> deg;

bool check;

P dfs(int v, int p) {
    vector<int> dp((int)g[v].size(), 0);
    int sz = (int)g[v].size();
    if(deg[v] == 1 && g[v][0] == p) {
        return {1, 1};
    }
    int sum = 0;
    for(int i = 0; i < (int)g[v].size(); ++ i) {
        if(g[v][i] == p) continue;
        P df = dfs(g[v][i], v);
        dp[i] += df.fr;
        sum += df.sc;
    }
    int res = (g[v][0] != p ? dp[0] : dp[1]);
    rep(i, sz) {
        if(g[v][i] == p) continue;
        if(dp[i] % 2 != res % 2) {
            check = 1;
        }
    }
    return {res + 1, sum + 1};
}

void solve() {
	cin >> n;
    if(n == 3) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    g.assign(n, vector<int>());
    deg.assign(n, 0);
    rep(i, n - 1) {
        int a, b; cin >> a >> b; --a, --b;
        g[a].pb(b);
        g[b].pb(a);
        deg[a] ++;
        deg[b] ++;
    }
    check = 0;
    int r;
    rep(i, n) {
        if(deg[i] > 1) r = i;
    }
    P x = dfs(r, -1);
    int mi;
    if(check) {
        mi = 3;
    } else {
        mi = 1;
    }
    int ma = n - 1;
    rep(i, n) {
        if(deg[i] > 1) {
            int tmp = 0;
            for(int v: g[i]) {
                if(deg[v] == 1) {
                    ++ tmp;
                }
            }
            if(tmp > 1) {
                ma -= (tmp - 1);
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