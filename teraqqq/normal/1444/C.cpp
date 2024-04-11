#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt")

#include <immintrin.h>
#include <malloc.h>
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

mt19937 rng;

const int INF = 1e9;
const int MOD = 998244353;

const int N = 4e6+7;

int n, m, k;
int used[N], col[N], c[N], utm, ptr[N], sam[N], cnc, fail_g[N];
vi g[N];
vector<pi> edges;

bool check_2d(int v, int c = 0) {
    if(used[v] == utm) return true;
    used[v] = utm; sam[v] = c;

    for(int to : g[v]) {
        if(used[to] == utm && col[to] == col[v])
            return false;
        col[to] = 1 - col[v];
        if(!check_2d(to, c)) return false;
    }

    return true;
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> c[i], --c[i];

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; a--, b--;
        edges.eb(a, b);
        if(c[a] == c[b]) g[a].pb(b), g[b].pb(a);// cout << "! " << a+1 << ' ' << b+1 << endl;
    }

    ++utm;
    for(int i = 0; i < n; ++i) {
        if(!check_2d(i, ++cnc)) fail_g[c[i]] = true;
    }

    //for(int i = 0; i < n; ++i) cout << col[i]; cout << endl;
    //for(int i = 0; i < n; ++i) cout << sam[i]; cout << endl;

    for(int i = 0; i < n; ++i)
        g[i].resize(0);

    ll res = 0;
    for(int i = 0, t = 0; i < k; ++i)
        if(!fail_g[i]) res += t++;
    set<pi> calculated;
    map<pi, vector<pi>> to_calc;

    for(auto [a, b] : edges) {
        if(c[a] != c[b] && !fail_g[c[a]] && !fail_g[c[b]]) {

            const int u = sam[a]*2 + col[a];
            const int v = sam[b]*2 + col[b];
            //cout << "add edge " << u << ' ' << v << " if a=" << a << ", b=" << b << endl;
            int A = c[a], B = c[b]; if(A > B) swap(A, B);
            to_calc[{A, B}].eb(u, v);
        }
    }

    for(const auto& [_x, edges] : to_calc) {

        //cout << res << endl;
        for(auto [a, b] : edges) g[a].pb(b), g[b].pb(a), g[a].pb(a^1), g[b].pb(b^1), g[a^1].pb(a), g[b^1].pb(b);
            //cout << "add " << a << ' ' << b << endl;
        bool ok = true;
        ++utm;

        for(auto [a, b] : edges) {
            if(!check_2d(a)) { ok = false; break; }
            if(!check_2d(b)) { ok = false; break; }
        }
        if(!ok) --res;

        for(auto [a, b] : edges) g[a].resize(0), g[b].resize(0);
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    solve();
    //int t; cin >> t; while(t--) cout << solve() << '\n';
}