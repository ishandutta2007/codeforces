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
int n, q;
int pos[maxn];
int sz[maxn];
vi g[maxn], a;
void dfs(int u, int p) {
    pos[u] = a.size();
    a.pb(u);
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        g[p].pb(i);
    }
    dfs(1, 0);
    while (q--) {
        int u, k; scanf("%d %d", &u, &k);
        if (sz[u] < k) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", a[pos[u] + k - 1]);
    }
    return 0;
}