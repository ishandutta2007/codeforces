#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int sz[maxn];
double ans[maxn];

void getsz(int now, int fa) {
    sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        getsz(u, now);
        sz[now] += sz[u];
    }
}

void calans(int now, int fa, double ex) {
    ans[now] = ex;
    double a = 0.0, b = 0.0;
    int c = 0;
    sort(G[now].begin(), G[now].end(), [&](const int& i, const int& j) { return sz[i] < sz[j]; });
    int p = 1;
    for (int u : G[now]) if (u != fa) {
        a += p + ex; p += sz[u];
        ++c;
    }
    sort(G[now].begin(), G[now].end(), [&](const int& i, const int& j) { return sz[i] > sz[j]; });
    p = 1;
    for (int u : G[now]) if (u != fa) {
        b += p + ex; p += sz[u];
    }
    double avg = (a + b) / 2;
    int ind = 0;
    if (G[now][ind] == fa) ++ind;
    ind = G[now][ind];
    int tot = 0;
    for (int u : G[now]) if (u != fa) {
        tot += (sz[ind] - sz[u]);
    }
    double base = (avg - tot * 0.5) / (double)c;
    for (int u : G[now]) if (u != fa) {
        calans(u, now, base + (sz[ind] - sz[u]) * 0.5);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[i].emplace_back(p); G[p].emplace_back(i);
    }
    getsz(1, 0); calans(1, 0, 1.0);
    for (int i = 1; i <= n; ++i) cout << fixed << setprecision(10) << ans[i] << ' '; cout << endl;
    return 0;
}