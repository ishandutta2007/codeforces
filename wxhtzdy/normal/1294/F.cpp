#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int n;
int pa[maxn];
int dep[maxn];
int ds[maxn];
vi g[maxn];
vi pt;
void dfs(int u, int p) {
    pa[u] = p;
    for (int v : g[u])
        if (v != p)
            dep[v] = dep[u] + 1, dfs(v, u);
}
void dfs1(int u, int x) {
    pt.pb(u);
    if (u == x) return;
    dfs1(pa[u], x);
}
void bfs() {
    for (int i = 0; i < n; i++) ds[i] = 1e9;
    for (int i : pt) ds[i] = 0;
    set<pi> q;
    for (int i : pt) q.insert({0, i});
    while (!q.empty()) {
        int u = (*q.begin()).se;
        q.erase(q.begin());
        for (int v : g[u]) {
            if (ds[v] > ds[u] + 1) {
                q.erase({ds[v], v});
                ds[v] = ds[u] + 1;
                q.insert({ds[v], v});
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        --u, --v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0, 0);
    int st = 0;
    for (int i = 0; i < n; i++)
        if (dep[i] >= dep[st])
            st = i;
    int x = st;
    dep[st] = 0;
    dfs(st, st);
    for (int i = 0; i < n; i++)
        if (dep[i] >= dep[st])
            st = i;
    int ans = dep[st];
    if (ans == n - 1) {
        printf("%d\n", ans);
        for (int i = 0; i < n; i++) {
            if (i != x && i != st) {
                printf("%d %d %d", i + 1, x + 1, st + 1);
                break;
            }
        }
        return 0;
    }
    dfs1(st, x);
    int y = st;
    bfs();
    for (int i = 0; i < n; i++)
        if (ds[i] > ds[st]) st = i;
    printf("%d\n", ans + ds[st]);
    printf("%d %d %d", x + 1, y + 1, st + 1);
    return 0;
}