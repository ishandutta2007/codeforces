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

int n, m;
vector<int> a;
vector<vector<int>> g;

vector<int> color;
bool ok;
vector<bool> used;
int cnt0, cnt1;
int co;
vector<P> num;

void dfs(int v, int col) {
    color[v] = col;
    used[v] = 1;
    num[v] = {co, col};
    if(col == 0) ++ cnt0;
    else ++ cnt1;

    for(int nv: g[v]) {
        if(color[nv] == -1) {
            dfs(nv, 1 - col);
        } else if(color[nv] == 1 - col) {
            continue;
        } else {
            ok = 0;
            return;
        }
    }
}

void solve() {
	cin >> n >> m;
    a.resize(3);
    rep(i, 3) {
        cin >> a[i];
    }
    g.assign(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    color.assign(n, -1);
    used.assign(n, false);
    ok = 1;
    vector<P> vec;
    co = 0;
    num.resize(n);
    rep(i, n) {
        if(!used[i]) {
            cnt0 = 0, cnt1 = 0;
            dfs(i, 0);
            if(!ok) {
                cout << "NO" << endl;
                return;
            }
            vec.pb({cnt0, cnt1});
            ++ co;
        }
    }
    int sz = (int)vec.size();
    vector<vector<bool>> dp(sz + 1, vector<bool>(a[1] + 1, false));
    dp[0][0] = 1;
    rep(i, sz) {
        for(int j = 0; j <= a[1]; ++ j) {
            if(j + vec[i].fr <= a[1] && dp[i][j]) dp[i + 1][j + vec[i].fr] = 1;
            if(j + vec[i].sc <= a[1] && dp[i][j]) dp[i + 1][j + vec[i].sc] = 1;
        }
    }
    if(!dp[sz][a[1]]) {
        cout << "NO" << endl;
        return;
    } else {
        int cur = a[1];
        vector<int> s(sz);
        for(int i = sz - 1; i >= 0; -- i) {
            if(cur - vec[i].fr >= 0 && dp[i][cur - vec[i].fr]) {
                cur -= vec[i].fr;
                s[i] = 0;
                continue;
            }
            if(cur - vec[i].sc >= 0 && dp[i][cur - vec[i].sc]) {
                cur -= vec[i].sc;
                s[i] = 1;
            }
        }
        vector<int> ans(n, -1);
        rep(i, n) {
            if(s[num[i].fr] == num[i].sc) {
                ans[i] = 2;
            } else {
                if(a[0] > 0) {
                    ans[i] = 1;
                    a[0] --;
                } else {
                    ans[i] = 3;
                }
            }
        }
        cout << "YES" << endl;
        rep(i, n) {
            cout << ans[i];
        }
        cout << endl;
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