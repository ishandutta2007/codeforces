#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> graf[maxn], f[maxn];
bool forb[maxn], v[maxn];
int dp[maxn], to[maxn], sz[maxn];

int dfs(int now) {
    if (v[now]) return dp[now];
    dp[now] = sz[now]; to[now] = -1;
    for (int u : graf[now]) {
        if (sz[now] + dfs(u) > dp[now]) dp[now] = sz[now] + dfs(u), to[now] = u;
    }
    v[now] = true;
    return dp[now];
}

tuple<int, int, int> extgcd(int a, int b) {
    if (!b) return make_tuple(a, 1, 0);
    int d, x, y; tie(d, x, y) = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

int inverse(int a, int m) {
    int d, x, y; tie(d, x, y) = extgcd(a, m);
    // printf("a = %d, m = %d, d = %d, x = %d, y = %d\n", a, m, d, x, y);
    if (d > 1) return -1;
    return (x + m) % m;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        forb[x] = true;
    }
    for (int i = 0; i < m; ++i) if (!forb[i]) f[__gcd(i, m) % m].push_back(i), ++sz[__gcd(i, m) % m];
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < m; j += i) if (j != i) graf[i].push_back(j);
    }
    int ans = 0, bst = 0;
    for (int i = 0; i < m; ++i)  {
        if (dfs(i) > ans) ans = dfs(i), bst = i;
    }
    vector<int> vec;
    while (~bst) {
        for (int i : f[bst]) vec.push_back(i);
        bst = to[bst];
    } 
    vector<int> s = { vec[0] % m };
    for (int i = 1; i < vec.size(); ++i) {
        int g = __gcd(vec[i - 1], m);
        int inv = inverse(vec[i - 1] / g, m / g);
        assert(inv != -1);
        s.push_back((vec[i] * 1ll * inv / g + m) % m);
    }
    printf("%d\n", s.size());
    for (int i : s) printf("%d ", i); puts("");
    return 0;
}