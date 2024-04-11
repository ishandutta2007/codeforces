#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100050;
int n;
vi g[maxn];
int cn[maxn];
int ans[maxn];

void dfs(int u, int p, int k) {
    int deg = 0;
    for (int v : g[u]) {
        if (v != p) {
            deg++;
            dfs(v, u, k);
            if (cn[v] % k != 0) {
                cn[v]++;
                deg--;
            }
        }
    }
    cn[u] = deg;
}

int check(int k) {
    for (int i = 1; i <= n; i++) cn[i] = 0;
    dfs(1, 0, k);
    for (int i = 1; i <= n; i++) {
        if (cn[i] % k != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; scanf("%d %d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        ans[1] = ksm(2, n - 1);
        for (int k = 2; k <= n; k++) {
            if ((n - 1) % k != 0) {
                ans[k] = 0;
                continue;
            }
            ans[k] = check(k);
        }
        for (int i = n; i >= 1; i--) {
            for (int j = i + i; j <= n; j += i) {
                ans[i] -= ans[j];
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}