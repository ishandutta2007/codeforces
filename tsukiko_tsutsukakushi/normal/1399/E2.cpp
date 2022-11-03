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
typedef pair<int, P> P2;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, s;
vector<vector<P2>> g;

vector<vector<int>> cnt;

int dfs(int v, int p = -1) {
	int sz = g[v].size();
	cnt[v].assign(sz, -1);
	int co = (g[v].size() == 1 && g[v][0].fr == p);
	rep(i, sz) {
		if(g[v][i].fr == p) continue;
		cnt[v][i] = dfs(g[v][i].fr, v);
		co += cnt[v][i];
	}
	return co;
} 

void solve() {
	cin >> n >> s;
	g.assign(n, vector<P2>());
	rep(i, n - 1) {
		int u, v, w, c; cin >> u >> v >> w >> c;
		-- u, -- v;
		g[u].push_back(P2{v, P{w, c}});
		g[v].push_back(P2{u, P{w, c}});
	}
	cnt.assign(n, vector<int>());
	priority_queue<P2> pque1;
    priority_queue<P2> pque2;
	dfs(0);
	int sum1 = 0, sum2 = 0;
	rep(v, n) {
		for(int i = 0; i < g[v].size(); ++ i) {
			if(cnt[v][i] != -1) {
                if(g[v][i].sc.sc == 1) {
                    sum1 += g[v][i].sc.fr * cnt[v][i];
				    pque1.push(P2{(g[v][i].sc.fr - g[v][i].sc.fr / 2) * cnt[v][i], P{g[v][i].sc.fr / 2, cnt[v][i]}});
                } else {
                    sum2 += g[v][i].sc.fr * cnt[v][i];
				    pque2.push(P2{(g[v][i].sc.fr - g[v][i].sc.fr / 2) * cnt[v][i], P{g[v][i].sc.fr / 2, cnt[v][i]}});
                }
			}
		}
	}
    vector<int> a1, a2;
    int sum1_ = sum1, sum2_ = sum2;
	while(sum1 > 0) {
		P2 p = pque1.top(); pque1.pop();
		sum1 -= p.fr;
        a1.push_back(p.fr);
		pque1.push(make_pair((p.sc.fr - p.sc.fr / 2) * p.sc.sc, make_pair(p.sc.fr / 2, p.sc.sc)));
	}
    while(sum2 > 0) {
		P2 p = pque2.top(); pque2.pop();
		sum2 -= p.fr;
        a2.push_back(p.fr);
		pque2.push(make_pair((p.sc.fr - p.sc.fr / 2) * p.sc.sc, make_pair(p.sc.fr / 2, p.sc.sc)));
	}
    int sz1 = (int)a1.size(), sz2 = (int)a2.size();
    vector<int> s1(sz1 + 1, 0), s2(sz2 + 1, 0);
    rep(i, sz1) {
        s1[i + 1] = s1[i] + a1[i];
    }
    rep(i, sz2) {
        s2[i + 1] = s2[i] + a2[i];
    }
    int need = sum1_ + sum2_ - s;
    if(need <= 0) {
        cout << 0 << endl;
        return;
    }
    int ans = inf;
    rep(i, sz1 + 1) {
        int res = 2 * (lower_bound(all(s2), need - s1[i]) - s2.begin()) + i;
        // cerr << res << endl;
        if(lower_bound(all(s2), need - s1[i]) == s2.end()) continue;
        chmin(ans, res);
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