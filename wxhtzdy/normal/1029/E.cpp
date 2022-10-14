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
int dep[maxn];
int par[maxn];
vi g[maxn];
void dfs(int u, int p) {
    par[u] = p;
    for (int v : g[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1, 0);
    set<pi> s;
    for (int i = 1; i <= n; i++) {
        if (dep[i] > 2) {
            s.insert(mp(-dep[i], i));
        }
    }
    int ans = 0;
    while (!s.empty()) {
        int x = par[(*s.begin()).se];
        s.erase(mp(-dep[par[x]],par[x]));
        s.erase(mp(-dep[x],x));
        for (int y : g[x]) {
            s.erase(mp(-dep[y], y));
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}