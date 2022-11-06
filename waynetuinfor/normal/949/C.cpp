#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define var(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 2e5 + 10;
int u[maxn], n, m, h, scc[maxn], c, dp[maxn], fr[maxn];
bool v[maxn], vvv[maxn];
vector<int> graf[maxn], rev[maxn], vv[maxn], tp;
vector<int> ng[maxn], res;

void add_edge(int a, int b) {
    graf[a].push_back(b);
    rev[b].push_back(a);
}

void dfs(int now) {
    v[now] = true;
    for (int u : graf[now]) if (!v[u]) dfs(u);
    tp.push_back(now);
}

void rdfs(int now) {
    scc[now] = c;
    vv[c].push_back(now);
    for (int u : rev[now]) if (!scc[u]) rdfs(u);
}

void ansr(int now) {
    for (int u : vv[now]) if (u <= n) res.push_back(u);
    if (fr[now] == -1) return;
    ansr(fr[now]);
}
int pdfs(int now) {
    if (vvv[now]) return dp[now];
    dp[now] = 0;
    for (int u : vv[now]) if (u <= n) dp[now]++;
    if (dp[now] == 0) dp[now] = maxn + maxn;
    int mn = maxn + maxn;
    for (int u : ng[now]) {
        int d = pdfs(u);
        if (d < mn) mn = d, fr[now] = u;
    }
    if (mn == maxn + maxn) fr[now] = -1;
    else dp[now] += mn;
    vvv[now] = true;
    return dp[now];
}
struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
    void merge(int a, int b) { p[find(a)] = find(b); }
} djs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i) cin >> u[i];
    djs.init();
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        if ((u[a] + 1) % h == u[b]) {
            add_edge(a, b); //add_edge(b + n, a + n);
        }
        if ((u[b] + 1) % h == u[a]) {
            add_edge(b, a); // add_edge(a + n, b + n);
        }
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i);
    reverse(tp.begin(), tp.end());
    for (int i : tp) if (!scc[i]) ++c, rdfs(i);
    // for (int i = 1; i <= n; ++i) cout << scc[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j : graf[i]) if (scc[j] != scc[i]) ng[scc[i]].push_back(scc[j]);
    }
    int bst = -1, ans = maxn + maxn;
    for (int i = 1; i <= n; ++i) {
        if (pdfs(scc[i]) < ans) {
            ans = pdfs(scc[i]);
            bst = i;
        }
    }
    ansr(scc[bst]);
    cout << res.size() << endl;
    for (int i : res) cout << i << ' '; cout << endl;
    return 0;
}