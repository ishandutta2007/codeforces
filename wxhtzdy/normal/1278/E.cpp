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
const int maxn = 500005;
int l[maxn], r[maxn], nxt;
vi g[maxn];
void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            l[v] = ++nxt;
        }
    }
    r[u] = ++nxt;
    reverse(g[u].begin(), g[u].end());
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    l[1] = ++nxt;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}