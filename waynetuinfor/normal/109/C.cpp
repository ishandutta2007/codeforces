#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<pair<int, int>> graf[maxn];
int sz[2][maxn];
long long ans = 0;

void dfssz(int now, int fa) {
    sz[0][now] = 1; sz[1][now] = 0;
    for (auto u : graf[now]) if (u.first != fa) {
        dfssz(u.first, now);
        sz[1][now] += sz[1][u.first];
        if (u.second) sz[1][now] += sz[0][u.first];
        else sz[0][now] += sz[0][u.first];
    }    
}

void dfsans(int now, int fa, vector<int> p) {
    int z = sz[1][now] + p[1]; 
    ans += (z - p[1]) * 1ll * p[1];
    ans += p[1] * 1ll * (p[1] - 1);
    for (auto u : graf[now]) if (u.first != fa) {
        int k = sz[1][u.first];
        if (u.second) k += sz[0][u.first];
        ans += (z - k) * 1ll * k;
        ans += k * 1ll * (k - 1);
    }
    vector<int> tp(p.begin(), p.end()); tp[0] += sz[0][now], tp[1] += sz[1][now];
    for (auto u : graf[now]) if (u.first != fa) {
        tp[1] -= sz[1][u.first];
        if (u.second) tp[1] -= sz[0][u.first];
        else tp[0] -= sz[0][u.first];
        if (u.second) dfsans(u.first, now, { 0, tp[0] + tp[1] });
        else dfsans(u.first, now, tp);
        if (u.second) tp[1] += sz[0][u.first];
        else tp[0] += sz[0][u.first];
        tp[1] += sz[1][u.first];
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        bool k = true;
        while (c) k &= (c % 10 == 4 || c % 10 == 7), c /= 10;
        graf[a].emplace_back(b, k), graf[b].emplace_back(a, k);
    }
    dfssz(1, 0); dfsans(1, 0, { 0, 0 });
    printf("%" PRId64 "\n", ans);
    return 0;
}