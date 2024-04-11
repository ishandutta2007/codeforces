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

int n, m, k;
vector<vector<int>> g;
vector<int> depth;
bool ok;
vector<int> st;

void dfs(int v, int p, int d) {
    depth[v] = d;
    st.push_back(v);
    int memo = -1;
    for(int nv: g[v]) {
        if(nv == p) continue;
        if(depth[nv] == -1) {
            dfs(nv, v, d + 1);
        } else {
            ok = 1;
            //cerr << depth[v] - depth[nv] << endl;
            if(depth[v] - depth[nv] <= k - 1) {
                //cycle
                cout << 2 << endl << depth[v] - depth[nv] + 1 << endl;
                int cur = st.size() - 1;
                while(true) {
                    cout << st[cur] + 1 << " ";
                    if(st[cur] == nv) break;
                    -- cur;
                }
                cout << endl;
                exit(0);
            } else {
                //independent set
                memo = nv;
                // cout << 1 << endl;
                // int cur = st.size() - 1;
                // int co = 0;
                // while(true) {
                //     cout << st[cur] + 1 << " ";
                //     ++ co;
                //     if(co == (k + 1) / 2) break;
                //     -- cur;
                //     -- cur;
                // }
                // cout << endl;
                // exit(0);
            }
        }
    }
    if(memo != -1) {
            cout << 1 << endl;
                int cur = st.size() - 1;
                int co = 0;
                while(true) {
                    cout << st[cur] + 1 << " ";
                    ++ co;
                    if(co == (k + 1) / 2) break;
                    -- cur;
                    -- cur;
                }
                cout << endl;
                exit(0);
    }
    st.pop_back();
}

vector<int> used2;
int cnt;

void dfs2(int v, int p, int used) {
    if(used) {
        used2[v] = 1;
        ++ cnt;
    }
    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs2(nv, v, (used ^ 1));
    }
}

void solve() {
	cin >> n >> m >> k;
    g.assign(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
    }
    depth.assign(n, -1);
    ok = 0;
    dfs(0, -1, 0);
    if(!ok) {
        used2.assign(n, 0);
        dfs2(0, -1, 1);
        cout << 1 << endl;
        if(cnt >= (k + 1) / 2) {
            int co = 0;
            rep(i, n) {
                if(co < (k + 1) / 2) {
                    if(used2[i]) {
                        cout << i + 1 << " ";
                        ++ co;
                    }
                }
            }
            cout << endl;
        } else {
            int co = 0;
            rep(i, n) {
                if(co < (k + 1) / 2) {
                    if(!used2[i]) {
                        cout << i + 1 << " ";
                        ++ co;
                    }
                }
            }
            cout << endl;
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